/*A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7*/
#include<bits/stdc++.h>
using namespace std;
int staircase(int n)
{
    if(n==0)
        return 1;
     if(n==1)
            return 1;
     if(n==2)
        return 2;
     return staircase(n-1)+staircase(n-2)+staircase(n-3);
}
int staircase2(int *dp,int n)
{
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    return dp[n];
}
int main()
{

    int n;
    cin>>n;
    int* dp=new int[n+1];
    cout<<staircase2(dp,n)<<endl;
    cout<<staircase(n)<<endl;
}
