/*
Pattern Matching using z algorithm and then returning the index of pattern*/
#include<bits/stdc++.h>
using namespace std;
void getZ(int *Z,string str)
{
    int l=0;
    int r=0;
    int n=str.length();
    for(int i=1;i<n;i++)
    {
        if(i>r)
        {
            l=i;
            r=i;
            while(r<n && str[r]==str[r-l])
            {
                r++;
            }
            Z[i]=r-l;
            r--;
        }
        else
        {
            int k=i-l;
            if(Z[k]<=r-i)
            {
                Z[i]=Z[k];
            }
            else
            {
                l=i;
                while(r<n && str[r]==str[r-l])
                    r++;
                Z[i]=r-l;
                r--;
            }
        }
    }
}
void MatchZ(string s,string t)
{
    int n=s.length();
    int m=t.length();
    string str=t+"$"+s;
    int c=str.length();
    int *Z=new int[n]();
    getZ(Z,str);
    for(int i=0;i<c;i++)
        if(Z[i]==m)
        cout<<i-m-1<<endl;
}
int main()
{
    string s,t;
    cin>>s>>t;
    MatchZ(s,t);
}
