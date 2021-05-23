#include<bits/stdc++.h>
using namespace std;
vector<int> v[10000];
int l=-1;
void DFS(int** edges,int n,int sv,bool* visitor)
{visitor[sv]=true;
    v[l].push_back(sv);
    for(int i=0;i<n;i++)
    {if(sv==i)
        continue;
        if(edges[sv][i]==1 && !visitor[i])
            DFS(edges,n,i,visitor);
    }
}
void BFS(int **edges,int n,int sv,bool* visitor)
{
    visitor[sv]=true;
    queue<int> q;
    q.push(sv);
    while(!q.empty())
    {int curr=q.front();
     q.pop();
     v[l].push_back(curr);
        for(int i=0;i<n;i++)
    { if(i==curr)
        continue;
            if(edges[curr][i]==1&& !visitor[i])
    {
        q.push(i);
        visitor[i]=true;
    }

    }
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
    {
        int s,d;
        cin>>s>>d;
        edges[s][d]=1;
        edges[d][s]=1;
    }
    bool* visitor1=new bool[n]();
    bool* visitor2=new bool[n]();
 //   cout<<"DFS"<<endl;

    for(int i=0;i<n;i++)
    {if(!visitor2[i])
    {l++;
        DFS(edges,n,i,visitor2);}}

    for(int i=0;i<=l;i++)
    {sort(v[i].begin(),v[i].end());
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

    //cout<<"BFS"<<endl;
    /*for(int i=0;i<n;i++)
    {if(!visitor2[i])
    {l++;
        BFS(edges,n,i,visitor2);}}
    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<v[i].size();j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }*/
}
