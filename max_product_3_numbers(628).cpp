class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int min1 = INT_MAX; // has the largest minimum largest
        int min2 = min1;    
        int max1 = INT_MIN;  // has the largest maximum number
        int max2 = max1;
        int max3 = max2;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            // max check
            if(nums[i] >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] >= max2)
            {
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] >= max3)
            {
                max3 = nums[i];
            }
            
            // min check
            
            if(nums[i] <= min1)
            {
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] <= min2)
            {
                min2 = nums[i];
            }
        }
        
        return max(min1*min2*max1 , max1*max2*max3); // 2 negative numbers give a positive number and the max1 has the largest value
    }
};
