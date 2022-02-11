class Solution {
public:
    int solve(int index , int target , vector<int> &nums , vector<vector<int>> &dp)
    {
        if(index==0)
        {
            if(nums[index]== 0 && target==0)
            {
                return 2;
            }
            else if(nums[index]!= 0 && target==0)
            {
                return 1;
            }
            else if(nums[index] == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
       int nt = solve(index-1 , target , nums , dp);
       int t = 0;
        if(target >= nums[index])
        {
            t = solve(index - 1 , target - nums[index] , nums , dp);
        }
        int count = t + nt;
        return dp[index][target] = count;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // s1 + s2 = sum , s1 - s2 = D
        
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum+= nums[i];
        }
        
        int find = (sum - target)/2;  // this should always be divisible by 2 
        if ( sum - target < 0 || (sum - target)%2!=0) // sum - target >= 0 as we have to find a positive number in the array and all the elements of the array are positive
        {
            return 0;
        }
        vector<vector<int>> dp(nums.size() , vector<int>(find + 1 , -1));
        return solve(nums.size()-1 , find , nums , dp);
    }
};
