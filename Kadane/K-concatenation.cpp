/*
You are given an array A with size N (indexed from 0) and an integer K. Let's define another array B with size N · K as the array that's formed by concatenating K copies of array A.

For example, if A = {1, 2} and K = 3, then B = {1, 2, 1, 2, 1, 2}.

You have to find the maximum subarray sum of the array B. Fomally, you should compute the maximum value of Bi + Bi+1 + Bi+2 + ... + Bj, where 0 ≤ i ≤ j < N · K.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers A0, A1, ..., AN-1.
Output
For each test case, print a single line containing the maximum subarray sum of B.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 105
1 ≤ K ≤ 105
-106 ≤ Ai ≤ 106 for each valid i
Subtasks
Subtask #1 (18 points): N · K ≤ 105

Subtask #2 (82 points): original constraints

Example
Input:

2
2 3
1 2
3 2
1 -2 1

Output:

9
2
Explanation
Example case 1: B = {1, 2, 1, 2, 1, 2} and the subarray with maximum sum is the whole {1, 2, 1, 2, 1, 2}. Hence, the answer is 9.

Example case 2: B = {1, -2, 1, 1, -2, 1} and the subarray with maximum sum is {1, 1}. Hence, the answer is 2.*/
#include<bits/stdc++.h>
using namespace std;
int kadane(int *arr,int n)
{
    int curr_sum=0;
    int max_sum=0;
    for(int i=0;i<n;i++)
    {
        curr_sum+=arr[i];
        max_sum=max(max_sum,curr_sum);
        if(curr_sum<0)
            curr_sum=0;
    }
    return max_sum;
}
int kcat(int *arr,int n,int k)
{
    int kadane_sum=kadane(arr,n);
    int suffix_sum=INT_MIN,prefix_sum=INT_MIN,curr_prefix=0,curr_suffix=0;
    for(int i=0;i<n;i++)
    {
        curr_prefix+=arr[i];
        prefix_sum=max(prefix_sum,curr_prefix);
    }
    int totalsum=curr_prefix;
    for(int i=n-1;i>=0;i--)
    {
        curr_suffix+=arr[i];
        suffix_sum=max(suffix_sum,curr_suffix);
    }
    if(totalsum<0)
    {
        return max(prefix_sum+suffix_sum,kadane_sum);
    }
    else
    {
        return max(prefix_sum+suffix_sum+totalsum*(k-2),kadane_sum);
    }
}

int main()
{ int t;
cin>>t;
while(t--)
    {int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<kcat(arr,n,k)<<endl;}
}
