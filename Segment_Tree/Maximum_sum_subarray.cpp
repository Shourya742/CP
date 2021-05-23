/*ou are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one
query per line.
Sample Input:
3
-1 2 3
1
1 2
Sample Output:
2

5
324 3 23 -234 32
3
1 4
3 5
5 9*/
#include<bits/stdc++.h>
using namespace std;
struct node{
int total;
int Max;
int prefix;
int suffix;
};
void build(int *arr,node* tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode].total=arr[start];
         tree[treeNode].Max=arr[start];
          tree[treeNode].prefix=arr[start];
           tree[treeNode].suffix=arr[start];
           return;
    }
    int mid=(start+end)/2;
    build(arr,tree,start,mid,2*treeNode);
    build(arr,tree,mid+1,end,2*treeNode+1);
    node ans1=tree[2*treeNode];
    node ans2=tree[2*treeNode+1];
    node ans;
    ans.total=ans1.total+ans2.total;
    ans.prefix=max(ans1.total+ans2.prefix,ans1.prefix);
    ans.suffix=max(ans2.suffix,ans2.total+ans1.suffix);
    ans.Max=max(ans1.Max,max(ans2.Max,max(ans1.prefix+ans2.suffix,max(ans1.total+ans2.prefix,ans2.total+ans1.suffix))));
    tree[treeNode]=ans;
}
node query(node *tree,int start,int end,int left,int right,int treeNode)
{
    if(start>right||end<left)
    {
        node a;
        a.total=0;
        a.Max=0;
        a.prefix=0;
        a.suffix=0;
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
    ans.total=ans1.total+ans2.total;
    ans.prefix=max(ans1.total+ans2.prefix,ans1.prefix);
    ans.suffix=max(ans2.suffix,ans2.total+ans1.suffix);
    ans.Max=max(ans1.Max,max(ans2.Max,max(ans1.prefix+ans2.suffix,max(ans1.total+ans2.prefix,ans2.total+ans1.suffix))));
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    node* tree=new node[4*n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(arr,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        node ans=query(tree,0,n-1,l-1,r-1,1);
        cout<<ans.Max<<endl;
    }
}
