/*You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 100000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2*/
#include<bits/stdc++.h>
using namespace std;
int lbs(int* arr,int n)
{
    int *inc=new int [n];
    int *dec=new int [n];
    inc[0]=1;
    dec[0]=1;
    for(int i=1;i<n;i++)
    {
        inc[i]=1;
        dec[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]>arr[j])
            {
                if(inc[j]+1>inc[i])
                    inc[i]=inc[j]+1;
            }

        }
    }
    for(int i=n-2;i>=0;i--)
        for(int j=n-1;j>=i;j--)
    {
        if(arr[j]<arr[i])
        {
            if(dec[i]<dec[j]+1)
                dec[i]=dec[j]+1;
        }
    }
    int *output=new int[n];
    for(int i=0;i<n;i++)
    {
        output[i]=dec[i]+inc[i]-1;
    }
    sort(output,output+n);
    return output[n-1];
}
int main()
{
    int n;
    cin>>n;
    int* arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<lbs(arr,n)<<endl;

}
