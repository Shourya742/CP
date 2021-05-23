/*
LONGEST INCREASING SUBSEQUENCE*/
#include<bits/stdc++.h>
using namespace std;
int lis(int *arr,int n)
{
    int *output=new int[n];
    output[0]=0;
    for(int i=1;i<n;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]>arr[i])
                continue;
            int possibleans=output[j]+1;
            if(possibleans>output[i])
                output[i]=possibleans;
        }
    }
    sort(output,output+n);
    int best=output[n-1];
    return best;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<lis(arr,n)<<endl;

}
