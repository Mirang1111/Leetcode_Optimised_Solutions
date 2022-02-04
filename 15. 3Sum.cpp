class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int x;
        map<int,int> m;
        vector<int> v;
        set<vector<int>>s;
        vector<vector<int>> ans;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            x = nums[i];
            for(int j = i+1 ; j < nums.size() ; j++)
            {
                if(m.find(0 - nums[j] - x)!=m.end())
                {

                    v.push_back(x);
                    v.push_back(nums[j]);
                    v.push_back(-(nums[j] + x));
                    sort(v.begin(),v.end());
                    if(s.find(v)==s.end())
                    {
                        ans.push_back(v);
                    }
                    s.insert(v);
                    v.clear();
                }
                
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};
