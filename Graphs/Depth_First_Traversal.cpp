/* DFS using Adjacency Matrix*/
#include<bits/stdc++.h>
using namespace std;
void DFS(int **edges,int n,bool* visitor,int sv)
{
    cout<<sv<<endl;
    visitor[sv]=1;
    for(int i=0;i<n;i++)
    {if(sv==i)
    continue;
        if(edges[sv][i]==1 && !visitor[i])
            DFS(edges,n,visitor,i);
    }
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
    {int f,s;
    cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool *visitor=new bool[n]();

    DFS(edges,n,visitor,0);
}
