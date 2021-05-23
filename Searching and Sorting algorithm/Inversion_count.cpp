/*Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4*/
#include<bits/stdc++.h>
using namespace std;
int Inversion_merge(int *arr,int start,int end,int mid)
{
    int i=start,j=mid+1,k=0;
    int temp[end-start+1];
    int count=0;
    while(i<=mid && j<=end)
    {
        if(arr[i]>arr[j])
        {
            count+=(mid+1-i);
            temp[k]=arr[j];
            j++;
            k++;
        }
        else if(arr[j]>arr[i])
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=arr[i];
            k++;
            i++;
            j++;
        }
    }
    k=0;
    for(int i=start;i<=end;i++)
        {
           arr[i]=temp[k];
           k++;
        }
        return count;
}
int Inversion_count(int *arr,int start,int end)
{ if(start>=end)
 return 0;
    int mid=(start+end)/2;
   int ans1= Inversion_count(arr,start,mid);
   int ans2= Inversion_count(arr,mid+1,end);
    int ans3=Inversion_merge(arr,start,end,mid);
    return ans1+ans2+ans3;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<Inversion_count(arr,0,n-1)<<endl;
}
