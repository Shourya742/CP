/*Print subsequence*/
#include<bits/stdc++.h>
using namespace std;
void Print_subs(string s,string output)
{
    if(s.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    Print_subs(s.substr(1),output);
    Print_subs(s.substr(1),output+s[0]);
}
int main()
{
    string s;
    cin>>s;
    string output;
    Print_subs(s,output);
}
