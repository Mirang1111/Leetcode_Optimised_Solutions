class Solution {
public:
    int dp[71][71][71];
    int solve(int i , int j1 , int j2 , vector<vector<int>> &grid , int c , int r)
    {
        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)
        {
            return -1e7;
        }
        if(i==r-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
            {
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2]!=-1)
        {
            return dp[i][j1][j2];
        }
        int maxe = -1e7;
        for(int dj1 = -1 ; dj1 <= +1 ; dj1++)
        {
            for(int dj2 = -1 ; dj2 <= +1 ; dj2++)
            {
                if(j1==j2)
                {
                    maxe = max(maxe,grid[i][j1] + solve(i+1,j1 + dj1 , j2 + dj2,grid , c , r));
                }
                else
                {
                    maxe = max(maxe, grid[i][j1] + grid[i][j2] + solve(i+1,j1+dj1,j2+dj2,grid , c  , r));
                }
                
            }
        }
        return dp[i][j1][j2] =  maxe;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int row = grid.size();
        int col = grid[0].size();
        return solve(0,0,col-1,grid,col , row);
    }
};
