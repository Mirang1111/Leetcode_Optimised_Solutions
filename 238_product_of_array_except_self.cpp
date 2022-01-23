class Solution {   // tc - n 
// sc - n
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int right_array[nums.size()]; // making a right array which contains the multiplication of all the elements 
        // towards the right from the given index of the array
        int lp = 1;  // left product which we keep on updating as we go forward
        int mul = 1;
        for(int i = nums.size() - 1 ; i >= 0 ; i--)
        {
            mul = mul*nums[i]; 
            right_array[i] = mul;
        }
        vector<int> ans;
        for(int i = 0 ; i < nums.size() - 1 ; i++)
        {
            ans.push_back(lp*right_array[i+1]);
                lp = lp*nums[i];  // updating the left array each time we move forward in the loop
        }
        ans.push_back(lp); // as we are moving till second last index of the array , now at the last index
        // we only have to consider the left product as the right product is not possible
        return ans;
    }
};
