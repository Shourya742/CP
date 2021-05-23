/*
Largest_sum_subarray
KADANE ALGORITHM*/
#include<bits/stdc++.h>
using namespace std;
int KADANE(int *arr,int n)
{
    int curr_sum=0;
    int max_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        if(curr_sum>max_sum)
            max_sum=curr_sum;
        if(curr_sum<0)
            curr_sum=0;
    }
    return max_sum;
}
int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<KADANE(arr,n)<<endl;
}
