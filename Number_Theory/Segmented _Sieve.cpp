/*In this problem you have to print all primes from given interval.
Input
t - the number of test cases, then t lines follows. [t <= 150]
On each line are written two integers L and U separated by a blank. L - lower bound of
interval, U - upper bound of interval. [2 <= L < U <= 2147483647] [U-L <= 1000000].
Output
For each test case output must contain all primes from interval [L; U] in increasing order.
Sample Input:
2
2 10
3 7
Sample Output:
2
3
5
7
3
5
7 */
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
#define pb push_back
typedef long long ll;
vector<int>* sieve()
{
    bool *prime=new bool[MAX];
    for(int i=0;i<MAX;i++)
        prime[i]=true;
    for(int i=2;i*i<MAX;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<MAX;j+=i)
            {

                prime[j]=false;
            }
        }

    }
    vector<int>* primes=new vector<int>();
    primes->pb(2);
    for(int i=3;i<MAX;i+=2)
    {
        if(prime[i])
        {
            primes->pb(i);
        }
    }
    return primes;
}
int main()
{ vector<int>* prime=sieve();
ll l,u;
cin>>l>>u;
int *segment=new int[u-l+1];
for(ll i=0;i<(u-l+1);i++)
    segment[i]=true;
for(ll i=0;prime->at(i)*(long long)prime->at(i)<=u;i++)
{
    ll k=prime->at(i);
    ll base=(l/k)*k;
    if(base<l)
        base+=k;
    for(int j=base;j<=u;j+=k)
    {
        segment[j-l]=false;
    }
    if(base==k)
    segment[base-l]=true;

}
for(ll j=0;j<(u-l+1);j++)
{
    if(segment[j])
        cout<<j+l<<" ";
}
}
