class Solution {
public:
    
    int find_pivot(vector<int> nums)
    {
        int s = 0;
        int e = nums.size()-1;
        while(s <= e)
        {
            int mid = e + (s-e)/2;
            if(mid < nums.size()-1 &&  nums[mid] > nums[mid+1])
            {
                return mid;
            }
            else if(mid > 0 && nums[mid] < nums[mid-1])
            {
                return mid-1;
            }
            
            else if(nums[s] > nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }
    
    int binary_search(vector<int> nums , int s  , int e , int target)
    {
        while(s <= e)
        {
            int mid = e + (s-e)/2;
            if(nums[mid]== target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        // findind the pivot element
        int pivot = find_pivot(nums);
        int ans;
        if(pivot==-1)
        {
            ans = binary_search(nums,0,nums.size()-1,target);
        }
        else if(nums[pivot]==target)
        {
            return pivot;
        }
        else if(nums[0]  > target)
        {
            ans = binary_search(nums,pivot+1,nums.size()-1,target);
        }
        else
        {
            ans = binary_search(nums,0,pivot-1,target);
        }
        return ans;
    }
};
