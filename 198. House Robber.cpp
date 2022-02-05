class Solution {
public:  // tc = n , sc = 2n
   int dp[101];
    int solve(vector<int> nums , int index)
    {
        if(index==0)
        {
            return nums[index];
        }
        if(index < 0)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int pick_house = nums[index] + solve(nums,index-2);
        int not_pick_house = solve(nums,index-1);
        int c = max(pick_house,not_pick_house);
        dp[index] = c;
        return c;
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,nums.size()-1);
    }
};
