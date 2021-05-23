/*Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Return Format :
The count the number of 3-cycles in the given Graph
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Sample Input:
3 3
1 2 3
2 3 1
Sample Output:
1*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int* [n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n]();
    }
    int u[e],v[e];
    for(int i=0;i<n;i++)
        cin>>u[i];
    for(int j=0;j<n;j++)
        cin>>v[j];
    for(int i=0;i<n;i++)
    {
        edges[u[i]-1][v[i]-1]=1;
        edges[v[i]-1][u[i]-1]=1;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {for(int j=0;j<n;j++)
     if(edges[i][j]==1)
     {
         for(int k=0;k<n;k++)
         {
             if(edges[i][k]==1 && k!=i && edges[k][j]==1)
                count++;
         }
     }


    }
  cout<<count/6;
}
