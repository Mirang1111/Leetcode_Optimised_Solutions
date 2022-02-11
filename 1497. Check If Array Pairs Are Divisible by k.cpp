class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        map<int,int> m;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            int rem = ((arr[i] % k) + k) % k;
            m[rem]++;
        }
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            int rem = ((arr[i] % k) + k) % k;
            
            if(rem==0)
            {
                if(m[rem]%2!=0)
                {
                    return false;
                }
            }
            else if(2*rem == k)
            {
                if(m[rem]%2!=0)
                {
                    return false;
                }
            }
            else
            {
                if(m[rem] != m[k-rem])
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
