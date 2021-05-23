/*
Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.*/
#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int s,d;
    cin>>s>>d;
    int arr[d];
    arr[0]=1;
    for(int i=1;i<d;i++)
        arr[i]=0;
    int c=d-1;
    s-=1;
    while(c!=0)
    { if(s<9)
    {arr[c]=s;
     break;
    }
     else
     {
         s-=9;
         arr[c]=9;
         c--;
     }

    }
    for(int i=0;i<d;i++)
        cout<<arr[i];
    cout<<endl;

}
