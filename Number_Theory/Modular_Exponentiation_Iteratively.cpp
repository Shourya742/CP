#include<bits/stdc++.h>
using namespace std;
#define MOD 5
int main()
{

    long a,b;
    cin>>a>>b;
    long ans=1;
    while(b!=0)
    {
        if((b&1)==1)
        {
            ans=(ans*a)%MOD;
        }
        a=(pow(a,2));
        a%=MOD;
        b=b/2;

    }
    cout<<(int)(ans+MOD)%MOD<<endl;

}
