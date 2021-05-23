/*Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input
The first line contains T, number of testcases.


T lines follows each containing the number N.
Output
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500

0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define MAX 1000001
typedef long long ll;
vector<int>* sieve()
{
    bool* prime=new bool[MAX];
    for(int i=0;i<MAX;i++)
        prime[i]=true;
    for(int i=2;i*i<MAX;i++)
    {

        if(prime[i])
        {

            for(int j=i*i;j<MAX;j+=i)
                prime[j]=false;
        }
    }
    vector<int>* primes=new vector<int>();
primes->pb(2);
for(int i=3;i<MAX;i+=2)
{
    if(prime[i])
        primes->pb(i);
}
return primes;
}
ll divisor(ll n,vector<int>* primes)
{
    ll result=1;
    for(int i=0;primes->at(i)<=n;i++)
    {
        ll count=0;
        ll k=primes->at(i);
        while(n/k!=0)
        {
            count+=(n/k)%MOD;
            k*=k;
        }
        result=(result*(count+1)%MOD)%MOD;
    }
    return result;
}
int main()
{
    vector<int>* prime=sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<divisor(n,prime)<<endl;
    }
}
