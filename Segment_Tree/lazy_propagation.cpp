/*
Lazy Propagation*/
#include<bits/stdc++.h>
using namespace std;
void build(int *arr,int *tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build(arr,tree,start,mid,2*treeNode);
    build(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);

}
void update(int* tree,int* lazy,int start,int end,int left,int right,int treeNode,int val)
{
    if(start>right || end<left)
        return;
    if(lazy[treeNode]!=0)
    {
        tree[treeNode]+=lazy[treeNode];
        if(start!=end)
        {
            lazy[2*treeNode]+=lazy[treeNode];
            lazy[2*treeNode+1]+=lazy[treeNode];
        }
        lazy[treeNode]=0;

    }
    if(start>=left && end<=right)
    {
        tree[treeNode]+=val;
        if(start!=end)
        {lazy[2*treeNode]+=val;
        lazy[2*treeNode+1]+=val;}
        return;
    }
    int mid=(start+end)/2;
    update(tree,lazy,start,mid,left,right,2*treeNode,val);
    update(tree,lazy,mid+1,end,left,right,2*treeNode+1,val);
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);

}
int query(int *tree,int* lazy,int start,int end,int left,int right,int treeNode)
{
    if(start>right || end<left)
    {
        return INT_MAX;
    }
    if(lazy[treeNode]!=0)
    {
      tree[treeNode]+=lazy[treeNode];
      if(start!=end)
      {
          lazy[2*treeNode]+=lazy[treeNode];
          lazy[2*treeNode+1]+=lazy[treeNode];
      }
    }
    if(start>=left && end<=right)
    {
      return tree[treeNode];
    }
    int mid=(start+end)/2;
int    ans1=query(tree,lazy,start,mid,left,right,2*treeNode);
   int ans2=query(tree,lazy,mid+1,end,left,right,2*treeNode+1);
    return min(ans1,ans2);
}
int main()
{
    int n;
    cin>>n;
    int *tree=new int[3*n]();
    int* lazy=new int[3*n]();
    int *arr=new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(arr,tree,0,n-1,1);
    update(tree,lazy,0,n-1,2,3,1,0);
    for(int i=1;i<3*n;i++)
        cout<<tree[i]<<endl;
    cout<<"segment tree"<<endl;
    for(int i=1;i<3*n;i++)
        cout<<lazy[i]<<endl;
        cout<<endl;
    cout<<query(tree,lazy,0,n-1,2,2,1);
}
