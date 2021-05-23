/*Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
Line 1 : Integer n
Output Format :
Required sum
Constraints :
1 <= T <= 300000
1 <= n <= 1000000
Sample Input 1 :
5
Sample Output 1 :
55
Sample Input 2 :
2
Sample Output 2 :
4*/
#include<bits/stdc++.h>
using namespace std;
#define n 1000007
typedef long long ll;
ll phi[n+1],l[n+1];
void ETF()
{
    for(int i=1;i<=n;i++)
        phi[i]=i;
    for(int i=2;i<=n;i++)
    {if(phi[i]==i)
    {phi[i]=i-1;
        for(int j=2*i;j<=n;j+=i)
        {
            phi[j]=(phi[j]*(i-1))/i;
        }
    }
}}
ll LCMSUM(int m)
{
    ETF();
    for(int i=1;i<=n;i++)
    {

        for(int j=i;j<=n;j+=i)
        {
            l[j]+=(i*phi[i]);
        }
    }
    ll ans=l[m];
    ans=(ans+1)*m;
    ans/=2;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        cout<<LCMSUM(k)<<endl;
    }
}
