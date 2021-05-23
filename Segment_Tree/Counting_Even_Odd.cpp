/*Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers.
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y.

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4*/
#include<bits/stdc++.h>
using namespace std;
struct node{
int odd,even;};
void build(int *arr,node* tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        if(arr[start]%2==0)
        {
            tree[treeNode].odd=0;
            tree[treeNode].even=1;
            return;

        }
        tree[treeNode].odd=1;
        tree[treeNode].even=0;
        return;
    }
    int mid=(start+end)/2;
    build(arr,tree,start,mid,2*treeNode);
    build(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode].odd=tree[2*treeNode].odd+tree[2*treeNode+1].odd;
    tree[treeNode].even=tree[2*treeNode].even+tree[2*treeNode+1].even;

}
void update(int *arr,node* tree,int start,int end,int idx,int val,int treeNode)
{
    if(start==end)
    {
        arr[idx]=val;
        if(val%2==0)
        {
            tree[treeNode].odd=0;
            tree[treeNode].even=1;
            return;

        }
        tree[treeNode].odd=1;
        tree[treeNode].even=0;
        return;

    }
    int mid=(start+end)/2;
    if(idx>mid)
    {
        update(arr,tree,mid+1,end,idx,val,2*treeNode+1);
    }
    else
    {
        update(arr,tree,start,mid,idx,val,2*treeNode);
    }
    tree[treeNode].odd=tree[2*treeNode].odd+tree[2*treeNode+1].odd;
    tree[treeNode].even=tree[2*treeNode].even+tree[2*treeNode+1].even;
}
node query(node* tree,int start,int end,int left,int right,int treeNode)
{
    if(start>right || end<left)
    { node a;
    a.odd=0;
    a.even=0;
     return a;
    }
    if(start>=left && end<=right)
    {
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    node ans1=query(tree,start,mid,left,right,2*treeNode);
    node ans2=query(tree,mid+1,end,left,right,2*treeNode+1);
    node ans;
    ans.odd=ans1.odd+ans2.odd;
    ans.even=ans1.even+ans2.even;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    node* tree=new node[4*n];
    build(arr,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--)
    {
        int c,l,r;
        cin>>c>>l>>r;
        if(c==0)
        {
            update(arr,tree,0,n-1,l-1,r,1);
        }
        else
        {
            node ans=query(tree,0,n-1,l-1,r-1,1);
            if(c==1)
                cout<<ans.even<<endl;
            else
                cout<<ans.odd<<endl;
        }
    }
}
