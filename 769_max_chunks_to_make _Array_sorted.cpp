class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0;
        int max_element = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            max_element = max(max_element , arr[i]);
            if(max_element==i)
            {
                count++;
            }
        
        }
        return count;
    }
};
