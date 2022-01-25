#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
		for(int i=0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	
	cout<<"Matrix after 90 degree rotation is "<<endl;
     
     for(int i = 0;i<n;i++)      // Code for the transpose of the matrix
     {
     	for(int j = 0; j<i;j++)
     	{
     		int temp = arr[i][j];
     		arr[i][j] = arr[j][i];
     		arr[j][i] = temp;
		 }
	 }
    
	for(int i = 0;i<n;i++)     // Code for the reverse of each row
	{
		for(int j = 0;j<n/2;j++)
		{
			int temp = arr[i][j];
			arr[i][j] = arr[i][n-1-j];
			arr[i][n-1-j] = temp;
		}
	
	}
		for(int i=0;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	
	
// 2 steps for this question
// 1) transpose of the matrix
// 2) reverse each row of the transposed matrix
}
