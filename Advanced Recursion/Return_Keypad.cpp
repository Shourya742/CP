/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf*/
#include<bits/stdc++.h>
using namespace std;
int subs(int n,string output[],string number[])
{
if(n==0)
{
    output[0]="";
    return 1;
}
int lastdigit=n%10;
int smallnumber=n/10;
string smalloutput[500];
int smallcount=subs(smallnumber,smalloutput,number);
string op=number[lastdigit];
int k=0;
    for(int i=0;i<op.length();i++)
    {
        for(int j=0;j<smallcount;j++)
        {
            output[k]=smalloutput[j]+op[i];
            k++;
        }
    }
    return k;
}

}

int main()
{
    int n;
    cin>>n;
    string number[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string output[1000];
    int d=subs(n,output,number);
    for(int i=0;i<d;i++)
        cout<<output[i]<<endl;
}
