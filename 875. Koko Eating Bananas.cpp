class Solution {
public:
    
   bool isSafe(vector<int>& piles, int h, int mid) {
        if(mid == 0) return false;
        
        int  req = 0;
        for(int i:piles) {
            req += ceil((1.0*i)/(1.0*mid));
            if(req > h) return false;
        }
        
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s = 0;
    //    int sum = 0;
        int maxe = INT_MIN;
        for(int i = 0 ; i < piles.size() ; i++)
        {
            maxe = max(maxe,piles[i]);
        }
        int e = maxe;
        int ans = -1;
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(isSafe(piles,h,mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        
        return ans;
        
    }
};
