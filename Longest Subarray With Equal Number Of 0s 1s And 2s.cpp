#include "bits/stdc++.h"
using namespace std;
int solution(vector<int> &v){
    int ans = 0;
    int countz = 0;
    int counto = 0;
    int countt = 0;
    map<string , int > m;
    for(int i = 0 ; i < v.size() ; i++)
    {
         if(v[i]==0)
         {
             countz++;
         }
         else if(v[i]==1)
         {
             counto++;
         }
         else
         {
             countt++;
         }

         string state = to_string(counto - countz) + "@" + to_string(countt - counto);

         if(state == "0@0")
         {
             ans = max(ans , i+1);
         }
         else if(m.find(state)==m.end())
         {
             m[state] = i;
         }
         else
         {
             ans = max(ans , i - m[state]);
         }
    }
    return ans;
   }


int main(){
    int n;cin>> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << solution(arr) << endl;
}

/*at every point count the number of 1s 0s and 2s 
everytime find counto - countz and countt - counto and keep on storing it in the hashmap until the same value is found
if the same value is found it means that in between the value of 1s 0s and 2s is same , thats why the gap remains preserved */
