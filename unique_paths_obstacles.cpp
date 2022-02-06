class Solution {
public:
    int dp[101][101];
    int solve(int i , int j , vector<vector<int>>& obstacleGrid)
    {
        if( i >= 0 && j >=0 && obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        if(i==0 && j==0)
        {
            return 1;
        }
        if(i < 0 || j < 0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int count = solve(i-1,j, obstacleGrid) + solve(i,j-1, obstacleGrid);
        dp[i][j] = count;
        return count;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        return solve(obstacleGrid.size() - 1 , obstacleGrid[0].size()-1, obstacleGrid);
    }
};
