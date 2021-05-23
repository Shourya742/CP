/*An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.
Constraints :
1<=N<=100
1<=M<=(N*(N-1))/2
1<=u[i],v[i]<=N
Input Format :
Line 1 : Two integers N and M
Line 2 : List u of size of M
Line 3 : List v of size of M
Output Return Format :
The count the number of connected groups of islands
Sample Input :
2 1
1
2
Sample Output :
1 */
#include<bits/stdc++.h>
using namespace std;
void find(int** edges,int n,bool* visitor,int sv)
{
    visitor[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
            continue;
        if(edges[sv][i]==1 && !visitor[i])
        find(edges,n,visitor,i);
    }
}
int DFS(int **edges,int n)
{ bool* visitor=new bool[n]();
int count=0;
for(int i=0;i<n;i++)
   {if(!visitor[i])
       {count++;
       find(edges,n,visitor,i);}}
    return count;
}
int main()
{
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
        edges[i]=new int[n];
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[s-1][f-1]=1;
        edges[f-1][s-1]=1;
    }
    cout<<DFS(edges,n);

}
