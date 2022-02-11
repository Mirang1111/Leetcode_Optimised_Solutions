#include<bits/stdc++.h>

int countSubarrays(int n, vector<int> &arr){
    // similar to largest subarray with zero sum , but we have to count the no of 
    // subarrays so we need to keep the count of every sum so that when we encounter
    // a sum leading to a zero sum subarray we add the occurences of that sum to the 
    // ans as that sum could have occured at different indexes and we need to keep the count
    // of the subarrays
    map<int,int> m;
    int sum = 0;
    int ans = 0;
    for(int i = 0 ; i < arr.size() ; i++)
    {
        sum = sum + arr[i];
        if(sum==0)
        {
            m[sum]++;
            ans = ans + m[sum]; 
        }
       else if(m.find(sum)==m.end())
        {
            m[sum]++;
        }
        else if(m.find(sum)!=m.end() && sum!=0)
        {
            ans = ans + m[sum];
            m[sum]++;
        }
    }
    return ans;
}
