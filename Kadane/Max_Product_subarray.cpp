/* MAX PRODUCT SUBARRAY*/
#include<bits/stdc++.h>
using namespace std;
int max_product(int *arr,int n)
{ int max_positive=1;
 int max_negative=1;
 int max_product=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            max_positive*=arr[i];
            max_negative=min(max_negative*arr[i],1);
        }
        else if(arr[i]==0)
        {
            max_negative=1;
            max_positive=1;
        }
        else
        {
            int temp=max_negative;
            max_negative=max_positive*arr[i];
            max_positive=max(1,temp*arr[i]);
        }
        max_product=max(max_product,max_positive);
    }
    return max_product;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        }
        cout<<max_product(arr,n)<<endl;
}
