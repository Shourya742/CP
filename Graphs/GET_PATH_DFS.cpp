/*Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :*/
#include<bits/stdc++.h>
using namespace std;
bool DFS(int **edges,int n,bool *visitor,vector<int>& output,int sv,int ev)
{
    if(sv==ev)
    {
        output.push_back(ev);
        return true;
    }
    visitor[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edges[sv][i]==1 && !visitor[i])
        {
            if(DFS(edges,n,visitor,output,i,ev))
            {
                output.push_back(sv);
                return true;

            }

        }
    }
    return false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int* [n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n]();
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    vector<int> output;
    int f,s;
    cin>>f>>s;
    bool *visitor=new bool[n]();
    if(DFS(edges,n,visitor,output,f,s))
    {
        for(int i=0;i<output.size();i++)
            cout<<output[i]<<" ";
    }
    else
        cout<<" ";
}
