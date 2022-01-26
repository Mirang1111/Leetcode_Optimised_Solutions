int ceilingInSortedArray(int n, int x, vector<int> &arr){
    if(x > arr[n-1])
    {
        return -1;
    }
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;
    while(s <= e)
    {
        int mid = e + (s-e)/2;
        if(arr[mid]==x)
        {
            ans = arr[mid];
            break;
        }
        else if(arr[mid] <  x)
        {
            s = mid + 1;
        }
        else
        {
            ans = arr[mid];
            e = mid - 1;
        }
    }
    return ans;
}

