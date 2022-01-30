class Solution {
public:
    int findPeakElement(vector<int>& nums) {
             int s = 0;
        int e = nums.size()-1;
        while(s < e)
        {
            int mid  = (s+e)/2;
            if(nums[mid] > nums[mid+1])
            {
                // you are in the decreasing part of the array , this may be the ans , but 
                // look at the left
                // this is why e != mid -1
                e = mid;
            }
            else
            {
                // you are in the ascending part of the array 
                // because we know that mid + 1 element > mid element 
                s = mid + 1;
            }
        }
        // in the end , start==end and pointing to the largest number because of the 2 checks
        // above , start and end are always trying to find the max element in the above 2 checks hence , when they are pointing to just one element , that is the maximum one , because that is what the checks say
        // more elaboration : at every point of time for start and end , they have the best possible answer till that time , and if we are saying that only one item is remaining , hence because of the above line that is the best possible answer
        return e;
    }
};
