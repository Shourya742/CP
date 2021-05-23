/*
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Sample Input :
babab
babba
Sample Output :
3*/
#include<bits/stdc++.h>
using namespace std;
int sequence(string s,string t,int si=0,int ti=0)
{
    if(si==s.length())
        return 10001;
    if(ti==t.length())
        return 1;
    int option1=sequence(s.substr(1),t.substr(1),si+1,ti+1);
    int index=-1;
    for( int i=ti;i<t.length();i++)
    if(t[i]==s[si])
    {
        index=i;
        break;
    }
    if(index==1)
        return 1;
    int option2=sequence(s.substr(1),t.substr(index+1),si+1,ti+index+1);
    return min(option1,option2);

}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<sequence(s,t,0,0)<<endl;
}
