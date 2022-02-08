int findWays(vector<int> &num, int tar)   // complexity same as memoize , just the stack spaoce is reduced by num.size()
{
    vector<vector<int>> dp(num.size() , vector<int> (tar+1));
    
    for(int i = 0 ; i < num.size() ; i++)
    {
        dp[i][0] = 1;
    }
    if(num[0] <= tar) dp[0][num[0]] = 1;
    
    for(int i = 1 ; i < num.size() ; i++)
    {
        for(int j = 1 ; j <= tar ; j++)
        {
            int not_taken = dp[i-1][j];
            int take = 0;
            if(j >= num[i])
            {
                take = dp[i-1][j-num[i]];
            }
            dp[i][j] = take + not_taken;
        }
    }
    return dp[num.size()-1][tar];
}
