#include<bits/stdc++.h>
using namespace std;
#define MOD 5
int pow(int a,int b)
{

    if(a==0)
        return 0;
    if(b==0)
        return 1;
    long ans;
    if(b%2==0)
    {
        long smallans=pow(a,b/2);
        ans=(smallans*smallans)%MOD;
    }
    else
    {
        long smallans=pow(a,b-1);
        ans=a%MOD;
        ans=(ans*smallans)%MOD;
    }
    return int((ans+MOD)%MOD);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<pow(a,b);
}
