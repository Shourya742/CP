/*A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input
Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.
Output
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints
T < 10000

1 ≤ a ≤ b ≤ 10^6

0 ≤ n ≤ 10
Sample Input
5
1 3 1
1 10 2
1 10 3
1 100 3
1 1000 0
Sample Output
2
2
0
8
1*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
int main()
{int *prime=new int[MAX];
for(int i=0;i<MAX;i++)
    prime[i]=0;
for(int i=2;i*i<MAX;i++)
{
    if(prime[i]==0)
    {
        for(int j=2*i;j<MAX;j+=i)
        {
            prime[j]+=1;
        }
        prime[i]=1;
    }

}
//for(int i=0;i<11;i++)
  //  cout<<prime[i]<<" ";
cout<<endl;
    int t;
cin>>t;
while(t--)
{ int a,b,n;
cin>>a>>b>>n;
 int count=0;
 for(int i=a;i<=b;i++)
    if(prime[i]==n)
    count++;
 cout<<count<<endl;


}

}
