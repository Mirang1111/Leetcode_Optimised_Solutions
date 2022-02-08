int solve(int index , int target , vector<int> arr , vector<vector<int>> &dp)  // tc - n*target , sc - n + n*target
{
    if(target==0)
    {
        return true;
    }
    if(index==0)
    {
        return (arr[0] == target);
    }
    if(dp[index][target]!=-1)
    {
        return dp[index][target];
    }
    bool not_take = solve(index-1,target,arr,dp);
    bool take = false;
    if(target >= arr[index])
    {
        take = solve(index-1,target-arr[index],arr,dp); 
    }
    bool ans = take | not_take;
    dp[index][target] = ans;
    return ans;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1 , vector<int> (k+1 , -1));
    return solve(n-1,k,arr , dp);
}
