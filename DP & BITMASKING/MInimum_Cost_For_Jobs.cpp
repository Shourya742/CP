#include<bits/stdc++.h>
using namespace std;
int minCost(int **cost,int n,int p,int mask,int *dp)
{
    if(p>=n)
        return 0;
    if(dp[mask]!=INT_MAX)
        return dp[mask];
        int minimum=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(!(mask&(1<<i)))
        {
            int ans=minCost(cost,n,p+1,(mask|(1<<i)),dp)+cost[p][i];
            minimum=min(ans,minimum);
        }
    }
    dp[mask]=minimum;
    return minimum;
}
int minCostI(int **cost,int n)
{
    int* dp=new int[1<<n];
    for(int i=0;i<(1<<n);i++)
        dp[i]=INT_MAX;
    dp[0]=0;
    for(int mask=0;mask<(1<<n)-1;mask++)
    { int temp=mask;
     int k=0;
    while(temp>0)
    {
        if((temp%2)==1)
        {k++;
        }
        temp/=2;
    }
    for(int i=0;i<n;i++)
    {
        if(!(mask&(1<<i)))
        {
          dp[mask|(1<<i)]=min(dp[mask|(1<<i)],dp[mask]+cost[k][i]);
        }
    }

    }
    return dp[(1<<n)-1];
}
int main()
{
    int n;
    cin>>n;
    int **cost=new int*[n];
    for(int i=0;i<n;i++)
    {
        cost[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
    }
    int *dp=new int[1<<n];
for(int i=0;i<(1<<n);i++)
    dp[i]=INT_MAX;
    cout<<minCost(cost,n,0,0,dp)<<endl;
    cout<<minCostI(cost,n)<<endl;
}
