/*
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15a
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).*/
#include<bits/stdc++.h>
using namespace std;
int merge(int *arr,int start,int end,int mid)
{
    int i=start,j=mid+1,k=0;
    int count=0;
    int temp[end-start+1];
    while(i<=mid && j<=end)
    {
        if(arr[i]>arr[j])
        { temp[k]=arr[j];
            j++;
            k++;

        }
        else if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            count+=arr[i]*(end-j+1);
            i++;
            k++;
        }
        else
            { temp[k]=arr[i];
             i++;
             j++;
             k++;
            }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        temp[k]=arr[j];
        //count+=(i-start);
        j++;
        k++;

    }
    k=0;
    for(int i=start;i<=end;i++)
        arr[i]=temp[k++];
 return count;
}
int Value(int *arr,int start,int end)
{
    if(start>=end)
        return 0;
    int mid=(start+end)/2;
    int ans1=Value(arr,start,mid);
    int ans2=Value(arr,mid+1,end);
    int ans3=merge(arr,start,end,mid);
    return ans1+ans3+ans2;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<Value(arr,0,n-1)<<endl;
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }
}
