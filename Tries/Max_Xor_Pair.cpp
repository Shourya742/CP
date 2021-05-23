/*
Finding max xor pair using Trie*/
#include<bits/stdc++.h>
using namespace std;
class trieNode{
public: trieNode* left;
        trieNode* right;
};
void insert(int n,trieNode* head)
{
    trieNode* curr=head;
    for(int i=31;i>=0;i--)
    {
        int b=(n>>i)&1;
        if(b==0)
        {
            if(!curr->left)
            {
                curr->left=new trieNode();
            }
            curr=curr->left;
        }
        else
        {
            if(!curr->right)
            {
                curr->right=new trieNode();
            }
            curr=curr->right;

        }
    }
}
int FIndMaxXor(trieNode* head,int* arr,int n)
{
    int Max=INT_MIN;

    for(int i=0;i<n;i++)
    {trieNode* curr=head;
        int val=arr[i];
        int curr_xor=0;
        for(int j=31;j>=0;j--)
        {
            int b=(val>>j)&1;
            if(b==0)
            {
                if(curr->right)
                {
                    curr_xor+=pow(2,j);
                    curr=curr->right;
                }
                else
                    curr=curr->left;
            }
            else
            {
                if(curr->left)
                {
                    curr_xor+=pow(2,j);
                    curr=curr->left;
                }
                else
                    curr=curr->right;
            }
        }
        if(curr_xor>Max)
            Max=curr_xor;
    }
    return Max;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    trieNode* head=new trieNode;
    for(int i=0;i<n;i++)
    {
        insert(arr[i],head);
    }
    cout<<FIndMaxXor(head,arr,n)<<endl;


}
