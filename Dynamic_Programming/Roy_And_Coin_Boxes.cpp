/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4*/
#include<bits/stdc++.h>
using namespace std;
int freq[100000001];
int main()
{
    int n,m;
    cin>>n>>m;
    int* arr=new int[n]();
    int *si=new int[n]();
    int *ei=new int [n]();
    while(m--)
    {
        int s,e;
        cin>>s>>e;
        si[s-1]++;
        ei[e-1]++;
    }
    arr[0]=si[0];
    arr[1]=si[1]+si[0]-ei[0];
int     Max=max(arr[0],arr[1]);
    for(int i=2;i<n;i++)
    { arr[i]=si[i]+arr[i-1]-ei[i-1];
    if(arr[i]>Max)
        Max=arr[i];    }
    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;
    }
    for(int i=Max-1;i>=1;i--)
        freq[i]+=freq[i+1];
    int q;
    cin>>q;
    while(q--)
    {
        int ind;
        cin>>ind;
        cout<<freq[ind]<<endl;
    }

}
