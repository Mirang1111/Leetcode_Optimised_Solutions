#include<iostream>
#include<string>
#include <bits/stdc++.h>
using namespace std;
int solution(string s, int k) {

map<char,int> m_i;
  for(auto it : s)
  {
    m_i[it]++;
  }
  if(k > m_i.size())
  {
    return 0;
  }
  int ans = 0;
  map<char,int> m;
  int i = 0;
  int j = 0;
  while(true)
  {
    bool f1 = false;
    bool f2 = false;
    while(i < s.length())
    {
      f1 = true;
         m[s[i]]++;
         if(m.size() > k)
         {
           break;
         
         }
         else  // just this change as compared to Longest K unique characters
         {
             ans = max(ans , i - j +1);
         }
         i++;
    }
    while( j < i && j < s.length())
    {
      f2 = true;
      if(m[s[j]] ==1)
      {
        m.erase(s[j]);
      }
      else
      {
        m[s[j]]--;
      }

      if(m.size() == k)
      {
        break;
      }
      j++;
    }
    i++ , j++;
    if(f1==false && f2==false)
    {
      break;
    }
  }

  return ans;
}



int main() {
  string str;
  getline(cin, str);
  int k;
  cin >> k;
  cout << solution(str, k);

