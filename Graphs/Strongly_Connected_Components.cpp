#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>* edges,int start,unordered_set<int> &visitor,stack<int> &finish)
{
    visitor.insert(start);
    for(int i=0;i<edges[start].size();i++)
    {int element=edges[start][i];
        if(visitor.count(element)==0)
        dfs(edges,element,visitor,finish);

    }
    finish.push(start);

}
void dfs2(vector<int>* edges,int start,unordered_set<int> &visitor,unordered_set<int>* component)
{
    visitor.insert(start);
    component->insert(start);
    for(int i=0;i<edges[start].size();i++)\
    {
        int element=edges[start][i];
        if(visitor.count(element)==0)
            dfs2(edges,element,visitor,component);
    }
}
unordered_set<unordered_set<int>*>* getscc(vector<int>* edges,vector<int>* edgesT,int n)
{
    unordered_set<int> visitor;
    stack<int> finishVertices;
    unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*> ();
    for(int i=0;i<n;i++)
    {
        if(visitor.count(i)==0)
        {  dfs(edges,i,visitor,finishVertices);

        }
    }
    visitor.clear();
    while(!finishVertices.empty())
    { unordered_set<int>* component=new unordered_set<int>();
        int element=finishVertices.top();
        finishVertices.pop();
        if(visitor.count(element)==0)
        {dfs2(edgesT,element,visitor,component);
        output->insert(component);}
    }
    return output;
}
int main()
{
    int n;
    cin>>n;
    vector<int>* edges=new vector<int>[n];
    vector<int>* edgesT=new vector<int>[n];
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {int s,f;
    cin>>s>>f;
        edges[s-1].push_back(f-1);
        edgesT[f-1].push_back(s-1);    }

     unordered_set<unordered_set<int>*>* components=getscc(edges,edgesT,n);
     unordered_set<unordered_set<int>*>::iterator it=components->begin();
     while(it!=components->end())
     {
         unordered_set<int>* component=*it;
         unordered_set<int> ::iterator it2=component->begin();
         while(it2!=component->end())
         {
             cout<<*it2+1<<" ";
             it2++;
         }
         cout<<endl;
         it++;
     }
}
