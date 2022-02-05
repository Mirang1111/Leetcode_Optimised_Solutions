class Solution {
public:
    int solve(vector<int> c1)
    {
        int prev2 = 0;
        int prev1 = c1[0];
        int cur = 0;
        int p = 0;
        int np = 0;
        for(int i = 1 ; i < c1.size() ; i++)
        {
            if(i==1)
            {
               p = c1[i] + prev2;
               np = prev1;
            }
            else
            {
                p = c1[i] + prev2;
                np = prev1;
            }
            cur = max(p,np);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        vector<int> ans1;
        vector<int> ans2;
        for(int i = 0 ; i < nums.size()-1 ; i++)
        {
            ans1.push_back(nums[i]);
        }
        for(int i = 1 ; i < nums.size() ; i++)
        {
            ans2.push_back(nums[i]);
        }
        
        int c1 = solve(ans1);
        int c2 = solve(ans2);
        return max(c1,c2);
    }
};
