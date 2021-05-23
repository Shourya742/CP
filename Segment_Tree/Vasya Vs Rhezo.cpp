/*Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has.
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior.
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5*/
#include<bits/stdc++.h>
using namespace std;
struct node{long long a,b,index;};
void build(node* arr,node* tree,int start,int end,int treeNode)
{
    if(start==end)
    {
        tree[treeNode].a=arr[start].a;
        tree[treeNode].b=arr[start].b;
        tree[treeNode].index=start;
        return;
    }
    int mid=(start+end)/2;
    build(arr,tree,start,mid,2*treeNode);
    build(arr,tree,mid+1,end,2*treeNode+1);
   if(tree[2*treeNode].a>tree[2*treeNode+1].a)
   { tree[treeNode]=tree[2*treeNode];

   }
   else if(tree[2*treeNode].a<tree[2*treeNode+1].a)
   {
       tree[treeNode]=tree[2*treeNode+1];
   }
   else if(tree[2*treeNode].a==tree[2*treeNode+1].a)
   {
       if(tree[2*treeNode].b>tree[2*treeNode+1].b)
        tree[treeNode]=tree[2*treeNode+1];
       else if(tree[2*treeNode].b<tree[2*treeNode+1].b)
        tree[treeNode]=tree[2*treeNode];
       else
       tree[treeNode]=tree[2*treeNode];
   }

}
node query(node* tree,int start,int end,int left,int right,int treeNode)
{
    if(start>right || end<left)
    {
        node n;
        n.a=INT_MIN;
        n.b =INT_MAX;
        n.index=-1;
        return n;
    }
    if(start>=left && end<=right)
    {
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    node ans1=query(tree,start,mid,left,right,2*treeNode);
    node ans2=query(tree,mid+1,end,left,right,2*treeNode+1);
    node ans;
     if(ans1.a>ans2.a)
   { ans=ans1;

   }
   else if(ans1.a<ans2.a)
   {
     ans=ans2;
   }
   else if(ans1.a==ans2.a)
   {
       if(ans1.b>ans2.b)
        ans=ans2;
       else if(ans1.b<ans2.b)
        ans=ans1;
       else
       ans=ans1;
   }
   return ans;

    }
int main()
{
    int n;
    cin>>n;
    node *arr=new node[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].a;
    for(int i=0;i<n;i++)
            cin>>arr[i].b;
     node* tree=new node[4*n];
    build(arr,tree,0,n-1,1);
    int q;
    cin>>q;
    while(q--)
    {int l,r;
     cin>>l>>r;
     node ans;
       ans=query(tree,0,n-1,l-1,r-1,1);
     cout<<ans.index+1<<endl;
    }
}
