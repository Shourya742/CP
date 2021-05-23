/*You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job.
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250*/
#include<bits/stdc++.h>
using namespace std;
struct JOBS{int s,f,profit;};
bool compare(JOBS a1,JOBS a2)
{
    return a1.f<a2.f;
}
int main()
{ int n;
cin>>n;
    JOBS arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].s>>arr[i].f>>arr[i].profit;
    int dp[n];
    sort(arr,arr+n,compare);
    dp[0]=arr[0].profit;
    for(int i=1;i<n;i++)
    {
        int index=-1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j].f<=arr[i].s)
            {
                index=j;
                break;
            }
        }
        if(index!=-1)
        {
            dp[i]=max(dp[i-1],dp[index]+arr[i].profit);
        }
        else
            dp[i]=max(dp[i-1],arr[i].profit);
    }
    cout<<dp[n-1]<<endl;
}
