/*Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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
void Print_Keypad(int n,string output,string option[])
{
    if(n==0)
    {
        cout<<output<<endl;
        return;
    }
    int remainder=n%10;
    int left=n/10;
    string op=option[remainder];
    for(int i=0;i<op.size();i++)
    { Print_Keypad(left,op[i]+output,option);

    }

}
int main()
{
    string option[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int n;
    cin>>n;
    string output;
    Print_Keypad(n,output,option);

}
