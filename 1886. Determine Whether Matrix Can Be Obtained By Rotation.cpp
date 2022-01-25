class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int i = 0;
        while (i < n*n) // n size matrix can be rotated n*n times to come to the original matrix and hence we have to check it n*n times 
        {
        for(int i = 0 ; i < n ;i++)
        {
            for(int j = 0; j < i ;j++)
            {
                swap(mat[i][j] , mat[j][i]);
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n/2 ; j++)
            {
                swap(mat[i][j] , mat[i][n-j-1]);
            }
        }
        bool flag = true;
        for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < n ;j++)
            {
                if(mat[i][j]!=target[i][j])
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
        {
            return true;
        }
            i++;
            
        }
        return false;
    }
};
