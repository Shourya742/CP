/*
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings.
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3.*/
#include<bits/stdc++.h>
using namespace std;
int count(string s,string t)
{
    if(t.length()==0)
        return s.length();
    if(s.length()==0)
        return t.length();
      if(s[0]==t[0])
      {
          return 1+count(s.substr(1),t.substr(1));
      }
      int o1=1+count(s.substr(1),t);
      int o2=1+count(s,t.substr(1));
      return min(o1,o2);
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<count(s,t)<<endl;
}
