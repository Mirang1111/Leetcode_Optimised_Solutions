class Solution {
  public:
    bool areKAnagrams(string str1, string str2, int k) {
        
        if(str1.length()!=str2.length())
        {
            return false;
        }
        
        map<char,int> m;
        
        for(auto it : str1)
        {
            m[it]++;
        }
        
        for(int i = 0 ; i < str2.length() ; i++)
        {
             if(m.find(str2[i])!=m.end()  && m[str2[i]] > 0)
             {
                 m[str2[i]]--;
             }
        }
        int count = 0;
        for(auto it = m.begin() ; it!=m.end() ; it++)
        {
    
            count  = count + it->second;
        }
        
        if( count <= k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/* subtract the frequencies of both the strings in the map and only count the positive frequencies
(not the negative ones) and check if they are smaller or greater than the value of k */
