/*Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1*/
#include<bits/stdc++.h>
using namespace std;
int MAX(int** MAT,int n,int m)
{
    int **dp=new int*[n];
    for(int i=0;i<n;i++)
        dp[i]=new int[m]();
    for(int i=0;i<n;i++)
            if(MAT[i][0]==0)
            dp[i][0]=1;
    for(int i=0;i<m;i++)
            if(MAT[0][i]==0)
            dp[0][i]=1;
   for(int i=1;i<n;i++)
    for(int j=1;j<m;j++)
      if(MAT[i][j]==0)
   { dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));

   }
   int Max=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if(Max<dp[i][j])
            Max=max(Max,dp[i][j]);
    }
    return Max;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int **MAT=new int*[n];
    for(int i=0;i<n;i++)
    {
        MAT[i]=new int[m];
        for(int j=0;j<m;j++)
            cin>>MAT[i][j];
    }
    cout<<MAX(MAT,n,m)<<endl;
}
