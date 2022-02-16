class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i = 0; i < arr.size() ; i++)
        {
            maxi = max(maxi , arr[i]);
            mini = min(mini , arr[i]);
        }
        
        int cd = (maxi - mini) / (arr.size() - 1)    ;
         map<int,int> m;
        for(auto it : arr)
        {
            m[it]++;
        }
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(m.find(mini + i*cd)== m.end())
            {
                return false;
            }
        }
        return true;
    }
};


/*find the min and the max element and then find the common difference
store all the elements of the array in the map
once the common difference is found check for (a + i*cd) element in the map
if it is not present then false else true */
