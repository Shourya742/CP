/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence.
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12*/
#include<bits/stdc++.h>
using namespace std;
struct node{
    int maximum;
    int smaximum;
};
void buildtree(int *arr,node *tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode].maximum=arr[start];
        tree[treeNode].smaximum=INT_MIN;
        return;
    }
    int mid=(start+end)/2;
    buildtree(arr,tree,start,mid,2*treeNode);
     buildtree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode].maximum=max(tree[2*treeNode].maximum,tree[2*treeNode+1].maximum);
    tree[treeNode].smaximum=min(max(tree[2*treeNode].maximum,tree[2*treeNode+1].smaximum),max(tree[2*treeNode].smaximum,tree[2*treeNode+1].maximum));
}
void updateTree(int * arr,node *tree,int start,int end,int idx,int val,int treeNode)
{
    if(start==end)
    {
        arr[idx]=val;
        tree[treeNode].maximum=val;
        tree[treeNode].smaximum=INT_MIN;
        return;
    }
    int mid=(start+end)/2;
    if(idx>mid)
    {updateTree(arr,tree,mid+1,end,idx,val,2*treeNode+1);}
    else
    {
        updateTree(arr,tree,start,mid,idx,val,2*treeNode);
    }
//    tree[treeNode]=tree[2*treeNode]+tree[2*treeNode+1];
  tree[treeNode].maximum=max(tree[2*treeNode].maximum,tree[2*treeNode+1].maximum); tree[treeNode].smaximum=min(max(tree[2*treeNode].maximum,tree[2*treeNode+1].smaximum),max(tree[2*treeNode].smaximum,tree[2*treeNode+1].maximum));

}
node query(node *tree,int start,int end,int left,int right,int treeNode)
{
    if(start>right || end<left)
    { node nullnode;
     nullnode.maximum=INT_MIN;
     nullnode.smaximum=INT_MIN;

     return nullnode;}
    if(start>=left && end<=right)
    return tree[treeNode];
    int mid=(start+end)/2;
    node ans1=query(tree,start,mid,left,right,2*treeNode);
    node ans2=query(tree,mid+1,end,left,right,2*treeNode+1);
    node ans;
    ans.maximum=max(ans1.maximum,ans2.maximum);
    ans.smaximum=min(max(ans1.maximum,ans2.smaximum),max(ans1.smaximum,ans2.maximum));
    return ans;

}
int main()
{
    int n,q;
    cin>>n;
    int *arr=new int[n];
    node *tree=new node[3*n]();
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>q;
    buildtree(arr,tree,0,n-1,1);
    updateTree(arr,tree,0,n-1,0,6,1);
  //  for(int i=1;i<3*n;i++)
    //    cout<<tree[i].maximum<<" "<<tree[i].smaximum<<endl;
    //cout<<endl;
    while(q--)
    {int l,r;
     char ch;
     cin>>ch;
     cin>>l>>r;
     if(ch=='Q')
     {node ans=query(tree,0,n-1,l-1,r-1,1);
cout<<ans.maximum+ans.smaximum<<endl;}
     else
         updateTree(arr,tree,0,n-1,l-1,r,1);
}}
