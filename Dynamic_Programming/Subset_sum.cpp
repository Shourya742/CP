/*Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes*/
#include<bits/stdc++.h>
using namespace std;
bool subset(int *val,int n,int sum)
{
    if(n==0)
        return false;
    if(sum==0)
        return true;
    if(val[0]<=sum)
        return subset(val+1,n-1,sum)||subset(val+1,n-1,sum-val[0]);
}
bool subseti(int *val,int n,int sum)
{
    bool **dp=new bool*[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=new bool[sum+1]();
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=val[i-1])
                dp[i][j]=dp[i-1][j]||dp[i-1][j-val[i-1]];
        }
    }
    return dp[n][sum];
}
bool subsetio(int *val,int n,int sum)
{
    bool **dp=new bool*[2];
    for(int i=0;i<2;i++)
        dp[i]=new bool[sum+1]();
    for(int i=0;i<2;i++)
        dp[i][0]=true;
        int temp=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            dp[temp][j]=dp[temp^1][j];
            if(j>=val[i-1])
                dp[temp][j]=dp[temp^1][j]||dp[temp^1][j-val[i-1]];
        }
        temp=temp^1;
    }
    return dp[temp^1][sum];
}

int main()
{
    int n;
    cin>>n;
    int *val=new int[n];
    for(int i=0;i<n;i++)
        cin>>val[i];
    int sum;
    cin>>sum;
    if(subset(val,n,sum))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
if(subseti(val,n,sum))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
if(subsetio(val,n,sum))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}
