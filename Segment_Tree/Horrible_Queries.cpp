/*World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8
0 5 7 14
1 4 8
Output:
80
508*/
#include<bits/stdc++.h>
using namespace std;
void buildtree(long long* arr,long long *tree,long long start,long long end,long long treeNode)
{
    if(start== end)
    {
        tree[treeNode]=arr[start];
        return;
    }
    long long mid=(start+end)/2;
    buildtree(arr,tree,start,mid,2*treeNode);
    buildtree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=(tree[2*treeNode]+tree[2*treeNode+1]);
}
void update(long long *tree,long long* lazy,long long start,long long end,long long left,long long right,long long treeNode,long long inc)
{
    if(start>end)
        return;
    if(lazy[treeNode]!=0)
    {
        tree[treeNode]+=lazy[treeNode]*(end-start+1);
        if(start!=end)
        {
            lazy[2*treeNode]+=lazy[treeNode];
            lazy[2*treeNode+1]+=lazy[treeNode];
        }
        lazy[treeNode]=0;
    }
    if(start>right || end<left)
        return;
    if(start>=left && end<=right)
    {
        tree[treeNode]+=inc*(end-start+1);
        if(start!=end)
        {
            lazy[2*treeNode]+=inc;
            lazy[2*treeNode+1]+=inc;
        }
        return;
    }
    long long mid=(start+end)/2;
    update(tree,lazy,start,mid,left,right,2*treeNode,inc);
    update(tree,lazy,mid+1,end,left,right,2*treeNode+1,inc);
    tree[treeNode]=(tree[2*treeNode]+tree[2*treeNode+1]);


}
long long query(long long *tree,long long *lazy,long long start,long long end,long long left,long long right,long long treeNode)
{
    if(start>end)
        return 0;
    if(lazy[treeNode]!=0)
    {
        tree[treeNode]+=lazy[treeNode]*(end-start+1);
        if(start!=end)
        {
            lazy[2*treeNode]+=lazy[treeNode];
            lazy[2*treeNode+1]+=lazy[treeNode];

        }
        lazy[treeNode]=0;
    }
    if(start>=left && end<=right)
        return tree[treeNode];
    if(start>right || end<left)
        return 0;
    long long mid=(start+end)/2;
    long long ans1=query(tree,lazy,start,mid,left,right,2*treeNode);
  long long ans2= query(tree,lazy,mid+1,end,left,right,2*treeNode+1);
    return (ans1+ans2);

}
int main()
{int t;
 cin>>t;
 while(t--)
 {// int arr[]={1,3,-2,4};
    //int *tree=new int[18]();
    //int *lazy=new int[18]();
   long long n;
    cin>>n;
     long long* arr=new long long[n]();
     int C;
     cin>>C;
    long long* tree=new long long[4*n]();
    long long* lazy=new long long[4*n]();
    buildtree(arr,tree,0,n-1,1);
     while(C--)
{long long k;
 cin>>k;
 if(k==0)
 {long long p,q,v;
  cin>>p>>q>>v;
     update(tree,lazy,0,n-1,p-1,q-1,1,v);}
 else if(k==1)
 {long long p,q;
  cin>>p>>q;
     cout<< query(tree,lazy,0,n-1,p-1,q-1,1)<<endl;}
  /*int i=1;i<12;i++)
        cout<<tree[i]<<" ";
    cout<<endl;
    for(int i=1;i<12;i++)
        cout<<lazy[i]<<" ";}
    */
}}}
