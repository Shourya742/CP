/*A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/
#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int* w,int *v,int W)
{
    if(n==0 || W==0)
        return 0;
    if(W>=w[0])
    {
        return max(v[0]+knapsack(n-1,v+1,w+1,W-w[0]),knapsack(n-1,v+1,w+1,W));

    }
    return knapsack(n-1,v+1,w+1,W);
}
int knapsackdp(int n,int *w,int* v,int W,int **dp)
{
      if(n==0 || W==0)
        return 0;
       if(dp[n][W]>0)
            return dp[n][W];
    if(W>=w[0])
    {
        return dp[n][W]=max(v[0]+knapsack(n-1,v+1,w+1,W-w[0]),knapsack(n-1,v+1,w+1,W));

    }
    return dp[n][W]=knapsack(n-1,v+1,w+1,W);
}
int knapsackI(int n,int *w,int *v,int W)
{int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
        dp[i]=new int[W+1]();
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(j>=w[i-1])
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
              else
              dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];

}
int knapsackoi( int wt[],int val[], int n, int W)
{

    int mat[2][W+1];
    memset(mat, 0, sizeof(mat));

    int i = 0;
    while (i < n)
    {
        int j = 0;

        if (i%2!=0)
        {
            while (++j <= W)
            {
                if (wt[i] <= j)
                    mat[1][j] = max(val[i] + mat[0][j-wt[i]],
                                    mat[0][j] );
                else
                    mat[1][j] = mat[0][j];
            }

        }

        else
        {
            while(++j <= W)
            {
                if (wt[i] <= j)
                    mat[0][j] = max(val[i] + mat[1][j-wt[i]],
                                     mat[1][j]);
                else
                    mat[0][j] = mat[1][j];
            }
        }
        i++;
    }
    return (n%2 != 0)? mat[0][W] : mat[1][W];
}
int main()
{
    int n;
    cin>>n;
    int *w=new int[n];
    int *v=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int W;
    cin>>W;
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
        dp[i]=new int[W+1]();
    cout<<knapsack(n,w,v,W)<<endl;
    cout<<knapsackdp(n,w,v,W,dp)<<endl;
      cout<<knapsackI(n,w,v,W)<<endl;
   cout<<knapsackoi( w, v, n, W)<<endl;

}
