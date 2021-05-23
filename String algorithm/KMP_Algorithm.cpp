#include<bits/stdc++.h>
using namespace std;
int *getlps(string pattern)
{
    int len=pattern.length();
    int *lps=new int[len];
    int i=1;
    int j=0;
    lps[0]=0;
    while(i<len)
    {
        if(pattern[i]==pattern[j])
        {
            lps[i]=j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
bool KMPsearch(string s,string t)
{
    int textlen=s.length();
    int patlen=t.length();
    int i=0;
    int j=0;
    int *lps=getlps(t);
    while(i<textlen && j<patlen)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    if(j==patlen)
        return true;
    return false;
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<KMPsearch(s,t)<<endl;
}
