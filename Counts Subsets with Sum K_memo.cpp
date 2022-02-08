int solve(int index , vector<int> &num , int tar , vector<vector<int>> &dp) // tc - num.size()*tar , sc - num.size()(stack space) + num.size()*tar
{
    if(tar==0)
    {
        return 1;
    }
    if(index==0)
    {
        return (num[index]==tar);
    }
    if(dp[index][tar]!=-1)
    {
        return dp[index][tar];
    }
    int not_taken = solve(index-1 , num, tar , dp);
    int taken = 0;
    if(tar >= num[index])
    {
        taken = solve(index-1 , num , tar - num[index] , dp);
    }
    int total = taken + not_taken;
    return dp[index][tar]  = total;
}

int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size() , vector<int> (tar+1,-1));
    return solve(num.size()-1,num,tar,dp);
}
