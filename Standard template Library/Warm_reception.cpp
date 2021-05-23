/*There is only one beauty parlour in the town CodingNinjasLand. The receptionist at the beauty parlor is flooded with appointment requests because the “Hakori” festival is round the corner and everyone wants to look good on it.
She needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. You have to tell the minimum number of chairs required such that none of the customers has to stand.
Input Format :
First line contains the number of customers that will come. Second line contains N space-separated integers which represent the arrival timings of the customer. Third line contains N space-separated integers which represent the departure timings of the customer. Arrival and departure timings are given in 24-hour clock.
Constraints:
1<= N <= 100
Arrival and departure timings lie in the range [0000 to 2359]
Time Limit: 1 second
Output Format :
You have to print the minimum number of chairs required such that no customer has to wait standing.
Sample Test Cases:
Sample Input 1 :
5
900 1000 1100 1030 1600
1900 1300 1130 1130 1800
Sample Output 1:
4
Explanation:
4 because at 1100 hours, we will have maximum number of customers at the shop, throughout the day. And that maximum number is 4. */
#include<bits/stdc++.h>
using namespace std;
struct fest{
int arr;
int dep;
int count=0;};
bool compare(fest a1,fest a2)
{
    return a1.dep<a2.dep;
}
bool compare2(fest a1,fest a2)
{
    return a1.count>a2.count;
}
int main()
{int n;
cin>>n;
fest a[n];
for(int i=0;i<n;i++)
{int p;
cin>>p;
    a[i].arr=p;
}
for(int i=0;i<n;i++)
{int p;
cin>>p;
    a[i].dep=p;
}
sort(a,a+n,compare);
for(int i=0;i<n;i++)
{ int departure=a[i].dep;
    for(int j=0;j<n;j++)
    { if(a[j].arr<=departure && a[j].dep>=departure)
         a[i].count++;

    }
}
sort(a,a+n,compare2);
cout<<a[0].count<<" ";
}
