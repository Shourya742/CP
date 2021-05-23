/*Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(int d,ll* arr,int n,int c)
{
    int count =1;
    int curr=arr[0];
    for(int i=1;i<n;i++)
    {
        int dis=arr[i]-curr;
        if(dis>=d)
            {count++;
            curr=arr[i];}
    }
    if(count>=c)
        return true;
    return false;
}
int main()
{ int t;
cin>>t;
while(t--)
    {int n,c;
    cin>>n>>c;
    ll arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr,arr+n);
    int start=0;
    int end=arr[n-1]-arr[0];
    int ans=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(check(mid,arr,n,c))
        {
            ans=mid;
            start=mid+1;
        }
        else
            end=mid-1;
    }
    cout<<ans<<endl;}
}
