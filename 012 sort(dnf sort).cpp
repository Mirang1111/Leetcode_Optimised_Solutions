class Solution {
public:
    void sortColors(vector<int>& nums) {
        // using dutch national flag algorithm
        // basic idea - nums[ 0 to low-1 ] we have zero , nums[high+1 to end ] we have two ,
        // nums[low to mid - 1] we have 1
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while(mid <= high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                    low++ , mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                 high--;
            }
        }
    }
};
