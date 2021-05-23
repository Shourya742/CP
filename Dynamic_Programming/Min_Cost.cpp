/*MINIMUM COST TO FROM 0,0 to n-1,n-1*/
#include<bits/stdc++.h>
using namespace std;
int mincount2(int **input,int n)
{
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=new int[n]();
    }
   dp[n-1][n-1]=input[n-1][n-1];
   for(int i=n-2;i>=0;i--)
   {
       dp[i][n-1]=input[i][n-1]+dp[i+1][n-1];
       dp[n-1][i]=input[n-1][i]+dp[n-1][i+1];
   }
   for(int i=n-2;i>=0;i--)
   {
       for(int j=n-2;j>=0;j--)
       {
           dp[i][j]=input[i][j]+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
       }
   }
   return dp[0][0];
}
int mincount(int** input,int n,int si,int se,int ei,int ee)
{
    if(si==ei && se==ee)
        return input[ei][ee];
    if(si>ei || se>ee)
        return INT_MAX;
    int option1=mincount(input,n,si+1,se,ei,ee);
    int option2=mincount(input,n,si+1,se+1,ei,ee);
    int option3=mincount(input,n,si,se+1,ei,ee);
    return input[si][se]+min(option1,min(option2,option3));
}
int main()
{
    int n;
    cin>>n;
    int **input=new int*[n];
    for(int j=0;j<n;j++)
    {
        input[j]=new int[n];
        for(int i=0;i<n;i++)
            cin>>input[j][i];
    }
    cout<<mincount(input,n,0,0,n-1,n-1)<<endl;
    cout<<mincount2(input,n)<<endl;
}
