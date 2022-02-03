class Solution {
public:
    int dp[1001];
    int f(int s , int n , vector<int> cost)
    {
        if(s >= n)
        {
            return 0;
        }
        if(dp[s]!=-1)
        {
            return dp[s];
        }
        int way1 = cost[s]  + f(s+1,n,cost);
        int way2 = cost[s] + f(s+2,n,cost);
        int ans = min(way1,way2);
        dp[s] =  ans;
        return ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int c1 = f(0,cost.size(),cost);
        int c2 = f(1,cost.size(),cost);
        return min(c1,c2);
        
    }
};
