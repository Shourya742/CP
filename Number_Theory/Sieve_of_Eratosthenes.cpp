/*Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3
Sample Output -
2*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	// Write your code here
    int n;
    cin>>n;
    bool *arr=new bool[n+1];
    for(int i=0;i<n+1;i++)
    { arr[i]=true;}

    arr[0]=false;
    arr[1]=false;
    for(int i=2;(i*i)<n+1;i++)
    {
        if(arr[i])
        {
            for(int j=i*i;j<n+1;j+=i)
            {
                arr[j]=false;
            }
        }
    }
    int count=0;
    cout<<endl;
    for(int i=0;i<n+1;i++)
    { if(arr[i])
        count++;
    }
    cout<<count<<endl;

    return 0;
}
