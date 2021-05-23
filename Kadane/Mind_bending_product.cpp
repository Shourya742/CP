/*
Mind bending product
space constraint and no use divisor operator*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
long *product=new long[n];
int lp=1;
for(int i=0;i<n;i++)
{
    product[i]=lp;
    lp*=arr[i];
}
int rp=1;
for(int i=n-1;i>=0;i--)
{ product[i]*=rp;
rp*=arr[i];

}
for(int i=0;i<n;i++)
    cout<<product[i]<<" ";
}
