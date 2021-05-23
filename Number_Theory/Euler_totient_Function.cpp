#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
int main()
{
    int *prime=new int[MAX];
    for(int i=0;i<MAX;i++)
    {
        prime[i]=i;
    }
    for(int i=2;i*i<MAX;i++)
    {
        if(prime[i]==i)
        {
            prime[i]=i-1;
            for(int j=2*i;j<MAX;j+=i)
            {
                prime[j]=(prime[j]/i)*(i-1);
            }
        }
    }
    for(int i=1;i<11;i++)
        cout<<prime[i]<<" ";
}
