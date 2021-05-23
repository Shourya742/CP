/*Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3*/
#include<bits/stdc++.h>
using namespace std;
int lcs2(string s1,string s2,int **dp)
{
    if(s1[0]=='\0'||s2[0]=='\0')
        return 0;
     if(dp[s1.length()][s2.length()]>0)
            return dp[s1.length()][s2.length()];
    if(s1[0]==s2[0])
        return dp[s1.length()][s2.length()]= 1+lcs2(s1.substr(1),s2.substr(1),dp);
    else
    {
        int o1=lcs2(s1.substr(1),s2,dp);
        int o2=lcs2(s1,s2.substr(1),dp);
        return dp[s1.length()][s2.length()]=max(o1,o2);
    }
}
int  lcs(string s1,string s2)
{
    if(s1[0]=='\0'||s2[0]=='\0')
        return 0;
    if(s1[0]==s2[0])
        return 1+lcs(s1.substr(1),s2.substr(1));
    else
    {
        int o1=lcs(s1.substr(1),s2);
        int o2=lcs(s1,s2.substr(1));
        return max(o1,o2);
    }
}
int lcsI(string s1,string s2)
{
    int **dp=new int *[s1.length()+1];
    for(int i=0;i<s1.length()+1;i++)
        dp[i]=new int[s2.length()+1]();
    for(int i=1;i<=s1.length();i++)
    {
        for(int j=1;j<=s2.length();j++)
        {
            if(s1[s1.length()-i]==s2[s2.length()-j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);        }
    }
    return dp[s1.length()][s2.length()];
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int **dp=new int *[s1.length()];
    for(int i=0;i<s1.length()+1;i++)
        dp[i]=new int[s2.length()+1]();
    cout<<lcs(s1,s2)<<endl;
    cout<<lcs2(s1,s2,dp)<<endl;
    cout<<lcsI(s1,s2)<<endl;
}
