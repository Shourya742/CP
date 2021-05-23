/*
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").*/

#include<bits/stdc++.h>
using namespace std;
int* GetMaxPal(string s)
{
    int n=s.length();
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        arr[i]=1;
    for(int i=0;i<n;i++)
    {
        int l=i;
        int r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {int curr_length=r-l+1;
            if(curr_length>1)
            arr[i]++;
            r++;
            l--;
        }
        l=i;
        r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {int curr_length=r-l+1;
            if(curr_length>1)
            arr[i]++;
            r++;
            l--;
        }

    }
    return arr;
}
int main()
{
    string s;
    cin>>s;
    int *arr=GetMaxPal(s);
    int sum=0;
    for(int i=0;i<s.length();i++)
        sum+=arr[i];
        cout<<sum<<endl;
}
