/*
We will use the following (standard) definitions from graph theory. Let V be a non-empty and finite set, its elements being called vertices (or nodes). Let E be a subset of the Cartesian product V×V, its elements being called edges. Then G=(V,E) is called a directed graph.

Let n be a positive integer, and let p=(e1,…,en) be a sequence of length n of edges ei∈E such that ei=(vi,vi+1)for a sequence of vertices (v1,…,vn+1). Then p is called a path from vertex v1 to vertex vn+1 in G and we say that vn+1 is reachable from v1, writing (v1→vn+1).

Here are some new definitions. A node v in a graph G=(V,E) is called a sink, if for every node w in G that is reachable from v, v is also reachable from w. The bottom of a graph is the subset of all nodes that are sinks, i.e., bottom(G)={v∈V∣∀w∈V:(v→w)⇒(w→v)}. You have to calculate the bottom of certain graphs.
Input Specification
The input contains several test cases, each of which corresponds to a directed graph G. Each test case starts with an integer number v, denoting the number of vertices of G=(V,E) where the vertices will be identified by the integer numbers in the set V={1,…,v}. You may assume that 1≤v≤5000. That is followed by a non-negative integer e and, thereafter, e pairs of vertex identifiers v1,w1,…,ve,we with the meaning that (vi,wi)∈E. There are no edges other than specified by these pairs. The last test case is followed by a zero.
Output Specification
For each test case output the bottom of the specified graph on a single line. To this end, print the numbers of all nodes that are sinks in sorted order separated by a single space character. If the bottom is empty, print an empty line.
Sample Input
3 3
1 3 2 3 3 1
2 1
1 2
0
Sample Output
1 3
2*/
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
{ while(true)
    {
        int n;
    cin>>n;
    if(n==0)
        break;
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
         unordered_set<int> ::iterator it3=it2;
         unordered_set<int> ::iterator it4=it2;
       int  flag=0;
       while(it3!=component->end())
       {
           for(int i=0;i<edges[*it3].size();i++)
            if(component->count(edges[*it3][i])==0)
           {
               flag=1;
               break;
           }
           if(flag)
            break;
            it3++;
       }
         if(flag==0)
         {int arr[1000];
          int k=0;
             while(it2!=component->end())
         {
             arr[k]=*it2+1;
                 k++;
             it2++;
         }
         sort(arr,arr+k);
          for(int i=0;i<k;i++)
              cout<<arr[i]<<" ";
         cout<<endl;
         }
         it++;
     }
    }
}
