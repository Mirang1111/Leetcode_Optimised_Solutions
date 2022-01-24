class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        vector<int> o;
        vector<int> e;
        for(int i = 0 ; i< nums.size() ; i++)
        {
            if(nums[i]%2==0)
            {
                e.push_back(nums[even]);
            }
            else
            {
                o.push_back(nums[odd]);
            }
            even++;
            odd++;
        }
        
        for(int i = 0 ; i < o.size() ; i++)
        {
            e.push_back(o[i]);
        }
        return e;
    }
};class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd = 0;
        int even = 0;
        vector<int> o;
        vector<int> e;
        for(int i = 0 ; i< nums.size() ; i++)
        {
            if(nums[i]%2==0)
            {
                e.push_back(nums[even]);
            }
            else
            {
                o.push_back(nums[odd]);
            }
            even++;
            odd++;
        }
        
        for(int i = 0 ; i < o.size() ; i++)
        {
            e.push_back(o[i]);
        }
        return e;
    }
};
