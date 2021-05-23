/*
Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
last index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
3*/
#include<bits/stdc++.h>
using namespace std;
int Find_last(int *arr,int size,int n,int x)
{
    if(size==n)
        return -1;
    if(arr[0]==x)
        return n-size;
    return Find_last(arr-1,size+1,n,x);
}
int Find_last2(int *arr,int size,int x)
{
    if(size==0)
        return -1;
    int smalloutput=Find_last2(arr+1,size-1,x);
    if(smalloutput!=-1)
        return 1+smalloutput;
    if(arr[0]==x)
        return 1;
    else
        return -1;

}
int main()
{
    int n;
    cin>>n;
    int* arr=new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        int x;
        cin>>x;
    cout<<Find_last2(arr,n,x);
}
