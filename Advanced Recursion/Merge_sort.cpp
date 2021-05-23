/*
Merge Sort
order of nlogn time complexity
order of n space complexity*/
#include<bits/stdc++.h>
using namespace std;
void Merge(int *arr,int start,int end,int mid)
{
    int i=start,j=mid+1,k=0;
    int temp[end-start+1];
    while(i<=mid && j<=end)
    {
        if(arr[i]>arr[j])
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
        else if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[i];
            i++;
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=end)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }
    int t=0;
    for(int i=start;i<end-start+1;i++)
        {arr[i]=temp[t];
        t++;}

}
void mergesort(int* arr,int start,int end)
{ if(start>=end)
    return;
    int mid=(start+end)/2;
mergesort(arr,start,mid);
mergesort(arr,mid+1,end);
Merge(arr,start,end,mid);

}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    mergesort(arr,0,n-1);
     for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
}
