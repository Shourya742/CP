/*LARGEST PALINDROMIC STRING
*/
#include<bits/stdc++.h>
using namespace std;
int GetMaxPal(string s)
{
    int n=s.length();
    int Max=0;
    for(int i=0;i<n;i++)
    {
        int l=i;
        int r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {int curr_length=r-l+1;
            Max=max(curr_length,Max);
            r++;
            l--;
        }
        l=i;
        r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {int curr_length=r-l+1;
            Max=max(curr_length,Max);
            r++;
            l--;
        }

    }
    return Max;
}
int main()
{
    string s;
    cin>>s;
    cout<<GetMaxPal(s)<<endl;
}
