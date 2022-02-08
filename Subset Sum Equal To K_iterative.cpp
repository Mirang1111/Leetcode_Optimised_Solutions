bool subsetSumToK(int n, int k, vector<int> &arr) {  // tc - n*k , sc - n*k for the vector
    vector<vector<bool>> dp(n+1 , vector<bool> (k+1 , 0));
    for(int i = 0 ; i < n ; i++)
    {
        dp[i][0] = true;
    }
  if(k >= arr[0])  dp[0][arr[0]] = true;
    
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <= k ; j++)
        {
            bool not_take = dp[i-1][j];
            bool take = false;
            if(j >= arr[i])
            {
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = take | not_take;
        }
    }
    return dp[n-1][k];
}

// memo to iterative steps
// 1) check the base case
// 2) number of for loops = number of parameters taken in the recusion function
// 3) if the recursion is top - down , then the tabulation is bottom up approach and vice versa
// 4) inside the for loops write the same recurrence relation just with the change that the function is replaced by the dp array
// 5) return the dp with the indexes which were passed in the recursion function
