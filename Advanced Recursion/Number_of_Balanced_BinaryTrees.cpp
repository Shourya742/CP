/*Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315*/
#include<bits/stdc++.h>
using namespace std;
int countBts(int h)
{
    if(h==1||h==0)
        return 1;
    int x=countBts(h-1);
    int y=countBts(h-2);
    int m=pow(10,9)+7;
    long long res1=(long long)x*x;
    long long res2=(long long)y*y;
    int ans1=(int)(res1%m);
    int ans2=(int)(res2%m);
    int ans=(ans1+ans2)%m;
    return ans;
}
int main()
{
    int h;
    cin>>h;
    cout<<countBts(h)<<endl;
}
