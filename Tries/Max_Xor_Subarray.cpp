/*Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000
Sample Input
4
1 2 3 4
Sample Output
7*/
#include<bits/stdc++.h>
using namespace std;
int Max=0;
class trieNode{
public:
    trieNode* left;
    trieNode* right;};
 void insert(int n,trieNode* head)
 {
     trieNode* curr=head;
     for(int i=31;i>=0;i--)
     {
         int b=(n>>i)&1;
         if(b==0)
         {
             if(!curr->left)
                curr->left=new trieNode();
           curr=curr->left;
         }
         else
         {
             if(!curr->right)
                curr->right=new trieNode();
             curr=curr->right;
         }
    }
 }
void MaxXorSub(trieNode* head,int n)
{ int curr=0;
 trieNode* c=head;
    for(int i=31;i>=0;i--)
{
    int b=(n>>i)&1;
    if(b==0)
    {
        if(c->right)
        {
            curr+=pow(2,i);
            c=c->right;
        }
        else
            c=c->left;
    }
   else
   {
       if(c->left)
       {
           curr+=pow(2,i);
           c=c->left;
       }
       else
           c=c->right;
   }

}
    Max=max(curr,Max);

}
int main()
{int n;
cin>>n;
int *arr=new int[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
trieNode* head=new trieNode();
int *XOR=new int[n];
    int c=0;
    XOR[0]=arr[0]^0;
    for(int i=1;i<n;i++)
    {
        XOR[i]=arr[i]^XOR[i-1];
    }
Max=XOR[0];
 insert(XOR[0],head);
for(int i=1;i<n;i++)
{
  MaxXorSub(head,XOR[i]);
    insert(XOR[i],head);
}

cout<<Max<<endl;
}
