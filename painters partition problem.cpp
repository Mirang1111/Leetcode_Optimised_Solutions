bool isSafe(vector<int> boards , int k , int mid)
{
    int painters = 1;
    int sum2 = 0;
    for(int i = 0 ; i < boards.size() ; i++)
    {
        sum2 = sum2 + boards[i];
        if(sum2 > mid)
        {
            painters++;
            sum2 = boards[i];
        }
        if(painters > k || boards[i] > mid)
        {
            return false;
        }
        
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    for(int i = 0 ; i < boards.size() ; i++)
    {
        sum = sum + boards[i];
    }
    int e = sum;
    int ans = -1;
    while(s <= e)
    {
        int mid = (s + e)/2;
        if(isSafe(boards,k,mid))
        {
            ans = mid;
            e = mid -1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
