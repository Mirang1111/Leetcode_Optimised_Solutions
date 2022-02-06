class Solution {
public:
    int dp[201][201];  // tc - n*m , sc - ((n-1) + (m-1)) + n*m
    int solve(int i , int j , vector<vector<int>> grid)
    {
        if(i==0 && j==0)
        {
            return grid[0][0];
        }
        if(i < 0 || j < 0)
        {
            return 1e9;  // such  a large number is returned so that any path will not 
            // take its value into consideration since it is out of bound and ans = min(both the paths)
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int path1 = grid[i][j] + solve(i-1,j,grid);
        int path2 = grid[i][j] + solve(i,j-1,grid);
        int ans = min(path1,path2);
        dp[i][j] = ans;
        return ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solve(grid.size()-1 , grid[0].size()-1,grid);
    }
};
