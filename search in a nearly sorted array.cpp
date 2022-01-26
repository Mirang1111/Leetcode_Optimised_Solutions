#include<bits/stdc++.h>
using namespace std;
int nearly_sorted_array(int *arr , int n, int k)
{
    int s = 0;
    int e = n-1;
    while(s <= e)
    {
        int mid = e + (s-e)/2;
        if(arr[mid]==k)
        {
            return mid;
        }
        else if( mid > 0 && arr[mid-1] == k)
        {
            return (mid-1);
        }
        else if(mid < n-1 && arr[mid+1]==k)
        {
            return mid + 1;
        }
        else if( arr[mid] > k )
        {
            e = mid - 2;
        }
        else
        {
            s = mid + 2;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans = nearly_sorted_array(arr,n,k);
    cout<<ans;
}
