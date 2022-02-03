#include<bits/stdc++.h>  
using namespace std;
int count(int n , int arr[])
{
	if(n==0)
	{
		return 1;
	}
	if(n<0)
	{
		return 0;
	}
	if(arr[n]!=0)
	{
		return arr[n];     // dp array return
	}

	int c1 = count(n-1,arr);
	int c2 = count(n-2,arr);   // pass array along with the function
	int c3 = count(n-3,arr);
	int c = c1 + c2 + c3;
	arr[n] = c;  // memoization
	return c;
}
int main()
{
	int n;
	cin>>n;
	int arr[n+1];
	for(int i = 0 ;i<n+1;i++)
	{
		arr[i] = 0;   // initialize the dp array to 0 everytime
	}
	int c = count(n,arr);
	cout<<"The number of ways to move down to the staircase is "<<c;
	return 0;
}
