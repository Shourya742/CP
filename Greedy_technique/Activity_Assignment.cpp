/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4*/
#include<bits/stdc++.h>
using namespace std;
struct activity{int s,e;};
bool compare(activity a,activity b)
{
    return a.e<b.e;
}
int main()
{
    int n;
    cin>>n;
    activity *arr=new activity[n]();
    for(int i=0;i<n;i++)
        cin>>arr[i].s>>arr[i].e;
     sort(arr,arr+n,compare);
     int count=1;
     int com=0;
     for(int i=1;i<n;i++)
     { //cout<<arr[i].s<<" "<<arr[i].e<<endl;
         if(arr[i].s>arr[com].e)
           {count++;
           com=i;}
     }
     cout<<count<<endl;
}
