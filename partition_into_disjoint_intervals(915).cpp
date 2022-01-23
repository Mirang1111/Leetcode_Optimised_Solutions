class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        // 1) make a right min array
        int right_min[nums.size()+1];
        right_min[nums.size()] = INT_MAX;
        for(int i = nums.size()-1 ; i >= 0 ; i--)
        {
            right_min[i]  = min(right_min[i+1],nums[i]);
        }
        // 2) make left_max and figure out the partition index
        int left_max = INT_MIN;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            left_max = max(left_max,nums[i]);
            count++;
            if(left_max <= right_min[i+1])
            {
                break;
            }
        
        }
        return count;
    }
};
