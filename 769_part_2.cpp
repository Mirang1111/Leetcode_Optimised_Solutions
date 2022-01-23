class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int right_min[arr.size()+1];
            right_min[arr.size()] = INT_MAX;
        for(int i = arr.size() -1 ; i >=  0 ; i--) // 1) generating the right min array where //the last element is infinity 
        {
            right_min[i] = min(right_min[i+1],arr[i]);
        }
 // 2) Iterate on array and manage left_max as well as count the chunks       
        int left_max = INT_MIN;
        int count = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            left_max = max(left_max,arr[i]);
                if(left_max <= right_min[i+1])
                {
                    count++;
                }
        }
        return count;
        
    }
};
