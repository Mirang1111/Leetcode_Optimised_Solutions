class Solution {   // tc - n*m , sc - ((n-1) + (m-1)) + n*m ( for the dp array )
public:
    int dp[101][101];   // bottom up recursion
    int solve(int j , int i, int m , int n)
    {
        if(j==m-1 && i==n-1)
        {
            return 1;
        }
        if(j >= m || i >=n)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int c = solve(j+1,i,m,n) + solve(j,i+1,m,n);
        dp[i][j] = c;
        return c;
        
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
    }
};
