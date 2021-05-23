/* Print Subsequence of string*/
#include<bits/stdc++.h>
using namespace std;
int subs(string input,string output[])
{
    if(input.empty())
    {
        output[0]="";
        return 1;
    }
    string smallstring=input.substr(1);
    int smalloutput=subs(smallstring,output);
    for(int i=0;i<smalloutput;i++)
    {
        output[i+smalloutput]=input[0]+output[i];
    }
    return 2*smalloutput;
}
int main()
{
    string input;
    cin>>input;
    string output[1000];
    int n=subs(input,output);
    for(int i=0;i<n;i++)
        cout<<output[i]<<endl;
}
