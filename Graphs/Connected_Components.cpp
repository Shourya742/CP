#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>* edges,int start,unordered_set<int> &visitor,unordered_set<int>* component)
{
    visitor.insert(start);
    component->insert(start);
    for(int i=0;i<edges[start].size();i++)
    {int element=edges[start][i];
        if(visitor.count(element)==0)
        { dfs(edges,element,visitor,component);


        }
    }
}
unordered_set<unordered_set<int>*>* getcc(vector<int>* edges,int n)
{
    unordered_set<int> visitor;
    unordered_set<unordered_set<int>*>* output=new unordered_set<unordered_set<int>*>();
    for(int i=0;i<n;i++)
    {
        if(visitor.count(i)==0)
            {unordered_set<int>* component=new unordered_set<int>();
                dfs(edges,i,visitor,component);
            output->insert(component);}
    }
    return output;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>* edges=new vector<int>[n];
    for(int i=0;i<m;i++)
    {
        int s,f;
        cin>>s>>f;
        edges[s-1].push_back(f-1);
        edges[f-1].push_back(s-1);
    }
    vector<int> :: iterator it3=edges->begin();
    unordered_set<unordered_set<int>*>* components=getcc(edges,n);
    unordered_set<unordered_set<int>*>:: iterator it=components->begin();
    while(it!=components->end())
    {
        unordered_set<int>* component=*it;
        unordered_set<int>:: iterator it1=component->begin();
        while(it1!=component->end())
        {
            cout<<*it1+1<<" ";
            it1++;
        }
        cout<<endl;
        it++;
    }
}
