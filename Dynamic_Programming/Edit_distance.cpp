/*Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2*/
#include<bits/stdc++.h>
using namespace std;
int Editdis(string s1,string s2,int**dp)
{
    if(s1.length()==0)
        return s2.length();
    if(s2.length()==0)
        return s1.length();
        if(dp[s1.length()][s2.length()]>0)
            return dp[s1.length()][s2.length()];
    if(s1[0]==s2[0])
        return dp[s1.length()][s2.length()]=Editdis(s1.substr(1),s2.substr(1),dp);
    int o1=1+Editdis(s1.substr(1),s2,dp);//delete
    int o2=1+Editdis(s1.substr(1),s2.substr(1),dp);//replace
    int o3=1+Editdis(s1,s2.substr(1),dp);// edit
    return dp[s1.length()][s2.length()]=min(o1,min(o2,o3));
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int **dp=new int*[s1.length()+1];
    for(int i=0;i<s1.length()+1;i++)
    {
        dp[i]=new int[s2.length()+1]();
    }
    cout<<Editdis(s1,s2,dp)<<endl;
}
