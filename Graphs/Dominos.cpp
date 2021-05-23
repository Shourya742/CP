/*Domino
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1*/
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
void dfs2(vector<int>* edges,int start,unordered_set<int> &visitor)
{
    visitor.insert(start);
    for(int i=0;i<edges[start].size();i++)
    {
        int element=edges[start][i];
        if(visitor.count(element)==0)
        {
            dfs2(edges,element,visitor);
        }
    }
}
int getscc(vector<int>* edges,vector<int>* edgesT,int n)
{
    unordered_set<int> visitor;
    stack<int> finished;
    for(int i=0;i<n;i++)
    {
        if(visitor.count(i)==0)
        {
            dfs(edges,i,visitor,finished);
        }
    }
    visitor.clear();
    int ans=0;
    while(!finished.empty())
    {
        int curr=finished.top();
        finished.pop();
        if(visitor.count(curr)==0)
        {ans++;
            dfs2(edges,curr,visitor);
        }
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>* edges=new vector<int>[n];
        vector<int>* edgesT=new vector<int>[n];
        int start=-1,e=-1;
        for(int i=0;i<m;i++)
        {int s,f;
        cin>>s>>f;
        if(i==0)
            start=min(s,f);
        if(i==m-1)
            e=max(s,f);
            edges[s-1].push_back(f-1);
            edgesT[f-1].push_back(s-1);
        }
        //cout<<start<<" "<<e<<endl;
        //edges[e-1].push_back(start-1);
        //edgesT[start-1].push_back(e-1);
        int ans=getscc(edges,edgesT,n);
        cout<<ans<<endl;

    }
}
