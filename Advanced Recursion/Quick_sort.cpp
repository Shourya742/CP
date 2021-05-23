/*
Quick-sort
time complexity-O(nlogn)*/
#include<bits/stdc++.h>
using namespace std;
int partition (int *arr,int start,int end)
{
    int pIndex=arr[end];
    int part=start;
    for(int i=start;i<=end;i++)
    {
        if(arr[i]<pIndex)
        {
            swap(arr[i],arr[part]);
            part++;
        }
    }
    swap(pIndex,arr[part]);
    return part;
}
void quicksort(int *arr,int start,int end)
{ if(start>=end)
return;
    int pIndex=partition(arr,start,end);
    quicksort(arr,start,pIndex-1);
    quicksort(arr,pIndex+1,end);
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
