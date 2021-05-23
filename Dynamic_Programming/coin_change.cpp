/*You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).*/
#include<bits/stdc++.h>
using namespace std;
int change(int*input,int n,int d)
{
    if(d==0)
        return 1;
    if(n==0)
        return 0;
    if(d<0)
        return 0;
    int option1=change(input,n,d-input[0]);
    int option2=change(input+1,n-1,d);
    return option1+option2;
}
int main()
{
    int n;
    cin>>n;
    int *input=new  int [n];
    for(int i=0;i<n;i++)
        cin>>input[i];
    int d;
    cin>>d;
    cout<<change(input,n,d)<<endl;
}
