/*Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
In different lines, ith vertex number and its distance from source (separated by space)
Constraints :
2 <= V, E <= 10^5
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*/
#include<bits/stdc++.h>
using namespace std;
int Findmin(bool *visitor,int *dis,int n)
{
    int minIndex=-1;
    for(int i=0;i<n;i++)

    {
        if(!visitor[i] && (minIndex==-1 && dis[minIndex]>dis[i]))
            minIndex=i;
    }
    return minIndex;
}
void dijkstra(int **edges,int n)
{
    bool *visitor=new bool[n]();
    int *dis=new int[n];
    memset(dis,INT_MAX,sizeof(dis));
    dis[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int minIndex=Findmin(visitor,dis,n);
        visitor[minIndex]=true;
        for(int j=0;j<n;j++)
        {
            if(!visitor[j] && edges[minIndex][j]!=0 && dis[j]>dis[i]+edges[minIndex][j])
            {
                dis[j]=dis[i]+edges[minIndex][j];

            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<i<<" "<<dis[i]<<endl;
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
        edges[i]=new int[n]();
    for(int i=0;i<e;i++)
    {
        int s,f,d;
        cin>>s>>f>>d;
        edges[s][f]=d;
        edges[f][s]=d;
    }
    dijkstra(edges,n);
}
