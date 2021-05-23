/*
pattern matching*/
#include<bits/stdc++.h>
using namespace std;
bool isMatch(string s,string p)
{
    int n=s.length();
    int m=p.length();

    for(int i=0;i<n-m;i++)
    {bool ans=true;
        for(int j=0;j<m;j++)
            if(s[i+j]!=p[j])
            {
                ans=false;
                break;
            }
            return ans;
        }
        return false;
}
int main()
{
    string s,p;
    cin>>s>>p;
    cout<<isMatch(s,p)<<endl;
}
