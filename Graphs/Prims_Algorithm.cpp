/*Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
MST
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5*/
#include<bits/stdc++.h>
using namespace std;
int Findmin(bool *visitor,int *weight,int n)
{
    int minIndex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visitor[i] && ((minIndex==-1)||(weight[i]<weight[minIndex])))
            minIndex=i;
    }
    return minIndex;
}
void prims(int **edges,int n)
{
    bool *visitor=new bool[n]();
    int *weight=new int[n];
    int *parent=new int[n]();
    parent[0]=-1;
    memset(weight,INT_MAX,sizeof(weight));
    weight[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int minVertex=Findmin(visitor,weight,n);
        visitor[minVertex]=true;
        for(int j=0;j<n;j++)
        {
          if(!visitor[j] && weight[j]>edges[minVertex][j] && edges[minVertex][j]!=0)
          {
              weight[j]=edges[minVertex][j];
              parent[j]=minVertex;

          }
        }
    }
    for(int i=1;i<n;i++)
        cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;

}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n]();
    }
    for(int i=0;i<e;i++)
    {
        int s,f,w;
        cin>>s>>f>>w;
        edges[s][f]=w;
        edges[f][s]=w;

    }
    prims(edges,n);
}
