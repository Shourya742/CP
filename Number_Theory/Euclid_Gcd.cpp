/*
Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
Input format :
x and y (separated by space)
Output format :
GCD of x and y
Sample Input 1:
20
5
Sample Output 1:
5
Sample Input 2:
96
14
Sample Output 2:
2*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{  if(a==0)
    return b;
    if(b==0)
        return a;
    if(a>b)
        return gcd(b,a%b);
    return gcd(b%a,a);
}
int main()
{

    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
}
