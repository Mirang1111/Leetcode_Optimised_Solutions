class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int ans = -1;
        vector<int> v;
        // first occurence code 
        
        int s = 0;
        int e = nums.size()-1;
        while(s <= e)
        {
            int mid = ( s + e )/2;
            if(nums[mid]==target)
            {
                ans = mid;
                e = mid - 1;
            }
            else if(nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        
        v.push_back(ans);
        
        // last occurence code
        int ans2 = -1;
        int a = 0;
        int b = nums.size()-1;
        while(a <= b)
        {
            int mid = (a+b)/2;
            if(nums[mid]==target)
            {
                ans2 = mid;
                    a = mid + 1;
            }
            else if(nums[mid] < target)
            {
                a = mid + 1;
            }
            else
            {
                b = mid - 1;
            }
        }
        v.push_back(ans2);
        return v;
    }
};
