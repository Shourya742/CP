#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int count=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if((mask&(1<<j))!=0)
               {
                   sum+=arr[j];
            }

        }
      //  cout<<sum<<endl;
        if(sum==k)
            count++;
    }
    cout<<count<<endl;
}
