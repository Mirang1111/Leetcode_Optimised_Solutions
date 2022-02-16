class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    map<int,int> m;
	    int ans = 0;
	    int sum = 0;
	    for(int i = 0 ; i < n ; i++)
	    {
	        sum = sum + arr[i];
	        
	        int rem = ((sum%k) + k)%k; // for negative numbers 
	       if(rem==0)
	       {
	           ans = max(ans , i + 1);
	       }
	       else if(m.find(rem)==m.end())   // if not present store the rem and the index in the hashmap
	        {
	            m[rem] = i;
	        }
	        else
	        {
	            ans =  max(ans , i - m[rem]);   // if present calculate the length of the subarray
	        }
	        
	    }
	    return ans;
	}
};
