bool isSafe(vector<int> arr , int n , int m , int mid)
{
    int student = 1;
    int sum2 = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum2 = sum2  + arr[i];
        if(sum2 > mid)
        {
            student++;
            sum2 = arr[i];
            if(student > m || arr[i] > mid) 
            {
                // students are more than the given students or if the value
                // of the ith element of the array is greater than the mid
                 return false;
            }
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m) {
    int s = 0; // minimum value of the search space 
     int sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        sum = sum + arr[i];
    }
    int e = sum; // maximum value of the search space
    int ans = -1;
    while(s <= e)
    {
        int mid = s + (e-s)/2;
        if(isSafe(arr,n,m,mid))
        {
            // if it is safe , then we have to check in the left half as we have
            // to minimize our answer , and in the right half values greater than 
            // mid will only be present 
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid + 1; // here we go in the right half as the left side would 
            // contain values lesser than the right half 
        }
    }
    return ans;
}
