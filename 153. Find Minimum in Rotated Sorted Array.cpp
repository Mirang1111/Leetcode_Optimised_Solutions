class Solution {
public:
    int find_pivot(vector<int> nums)
    {
        int s = 0;
        int e = nums.size()-1;
        while(s <= e)
        {
            int mid  = e + (s-e)/2;
            if(mid < nums.size() - 1 && nums[mid] > nums[mid+1])
            {
                return mid;
            }
            else if(mid > 0 && nums[mid-1] > nums[mid])
            {
                return mid-1;
            }
            else if(nums[s] >= nums[mid])
            {
                e = mid-1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        // finding the pivot element
        int pivot = find_pivot(nums);
        if(pivot==-1)
        {
            return nums[0];
        }
        else
        {
            return nums[(pivot+1)%(nums.size())];
        }
    }
};
