 public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        if(x < v[0]) // corner case given in the question
        {
            return -1;
        }
        
        long long s = 0;
        long long e = n-1;
        long long ans = -1;
        while(s <= e)
        {
            long long mid = e + ((s-e)/2);
            if(v[mid]==x)  // if the element is found in the array (element is the floor of itself)
            {
                ans = mid;
                break;
            }
            else if(v[mid] > x)  // here mid is not the possible answer as v[mid] is greater than x
            // and while finding the floor only elements lesser than the given element can be possible floors
            {
                e = mid - 1;
            }
            else
            {
            
                ans = mid;
                s = mid + 1;
            }
            
        }
        return ans;
    }
};

