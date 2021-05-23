/*
Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
Change in the input array itself. You don't need to return or print elements.
Input format :
Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer d
Output Format :
Updated array elements in a single line (separated by space)
Constraints :
0 <= N <= 10^7
0 <= d <= N
Sample Input 1:
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2
Sample Input 2:
7
1 2 3 4 5 6 7
0
Sample Output 2:
1 2 3 4 5 6 7*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
     cin>>arr[i];
    int d;
    cin>>d;
    while(d--)
    { int temp=arr[0];
        for(int i=0;i<n;i++)
        {
            arr[i%n]=arr[(i+1)%n];
        }
        arr[n-1]=temp;
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
