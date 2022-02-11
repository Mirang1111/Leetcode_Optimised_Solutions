class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> m;
        int sum = 0;
        m[0] = 1;
        int count = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum = sum + nums[i];
            if(m.find(sum-k)==m.end())
            {
                m[sum]++;
            }
            else
            {
                count = count + m[sum-k];
                m[sum]++;
            }
        }
        return count;
        
    }
};
