class Solution {    // same concept as moore vooting algorithm 
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1 = nums[0];
        int c1 = 1;
        int val2 = nums[0]; // assign any random value to it
        int c2 = 0;
        for(int i = 1 ; i < nums.size() ; i++)
        {
            if(nums[i]==val1)
            {
                c1++;
            }
            else if(nums[i]==val2)
            {
                c2++;
            }
            else
            {
                if(c1==0)
                {
                    val1  = nums[i];
                    c1 = 1;
                }
                else if(c2==0)
                {
                    val2 = nums[i];
                    c2  = 1;
                }
                else
                {
                    c1 -- , c2--;
                }
            }
        }
        int count1  = 0;
        int count2 = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i]==val1)
            {
                count1++;
            }
            if(nums[i]==val2)
            {
                count2++;
            }
        }
        vector<int> ans;
        if(count1 > (nums.size()/3))
        {
            ans.push_back(val1);
        }
        if(count2 > (nums.size()/3) && val1!=val2)
        {
            ans.push_back(val2);
        }
        return ans;
    }
};
