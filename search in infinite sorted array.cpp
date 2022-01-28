#include <bits/stdc++.h>   // searching in an infinite sorted array
using namespace std;
int binary_search(int l , int e , int key , int *arr)
{
    while(l <= e)
    {
        int mid = e + (l-e)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int answer(int *arr , int key)
{
    int l = 0;
    int e  = 1;
    while(arr[e] < key)
    {
        l = e;
        e = 2*e;
    }
    
    int s = binary_search(l,e,key,arr);
    return s;
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
    int key;
    cin>>key;
    int ans = answer(arr,key);
    if(ans==-1)
    {
        cout<<"The index is not present"<<endl;
    }
    else
    {
        cout<<"The index is present and it is "<<ans;
    }
    return 0;
}
