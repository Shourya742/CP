#include<bits/stdc++.h>
using namespace std;
void updateTree(int *arr,int* tree,int start,int end,int treeNode,int idx,int val)
{
    if(start==end)
    {
        arr[idx]=val;
        tree[treeNode]=val;
        return;
    }
    int mid=(start+end)/2;
    if(idx>mid)
    {
        updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,val);
    }
    else
    {
        updateTree(arr,tree,start,mid,2*treeNode,idx,val);
    }
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
}
int query(int *tree,int start,int end,int left,int right,int treeNode)
{ if(start>right || end<left)
   return 0;
  if(start>=left && end<=right)
    return tree[treeNode];
  int mid=(start+end)/2;
  int ans1=query(tree,start,mid,left,right,2*treeNode);
  int ans2=query(tree,mid+1,end,left,right,2*treeNode+1);
  return ans1+ans2;
}
void buildTree(int* arr,int* tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];

}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int* tree=new int[2*n];
    buildTree(arr,tree,0,n-1,1);
    updateTree(arr,tree,0,n-1,1,2,10);
    for(int i=1;i<2*n;i++)
            cout<<tree[i]<<" ";
            cout<<endl;
    int ans=query(tree,0,n-1,2,4,1);
    cout<<ans<<endl;


}
