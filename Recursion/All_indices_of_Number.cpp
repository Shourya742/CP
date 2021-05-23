/*
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
indexes where x is present in the array (separated by space)
Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4*/
#include<bits/stdc++.h>
using namespace std;
int Find_indices(int *arr,int size,int x,bool* visitor)
{
    if(size==0)
        return -1;
    if(arr[0]==x && !visitor[0])
        return 1;
    int count=1+Find_indices(arr+1,size-1,x,visitor+1);
    return count;
}
void Find_v(int *arr,int size,int x,bool* visitor,vector<int>& A)
{ int p=Find_indices(arr,size,x,visitor);
visitor[p]=true;
    A.push_back(p);
}
int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int x;
    cin>>x;
    bool *visitor=new bool[n]();
    vector<int> A;
    Find_v(arr,n,x,visitor,A);
    for(int i=0;i<A.size();i++)
        cout<<A[i]-1<<" ";
}
