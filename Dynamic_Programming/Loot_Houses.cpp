/*A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110*/
#include<bits/stdc++.h>
using namespace std;
int loot(int *arr,int n,int* dp)
{
    if(n==0)
        return 0;
     if(n==1)
            return arr[0];
       if(dp[n]>0)
                return dp[n];
    int option1=arr[0]+loot(arr+2,n-2,dp);
    int option2=loot(arr+1,n-1,dp);
    return dp[n]= max(option1,option2);
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    int *dp=new int[n]();
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<loot(arr,n,dp)<<endl;
}
