/*
Essential for KMP*/
#include<bits/stdc++.h>
using namespace std;
int* getLps(string s)
{
    int len=s.length();
    int *arr=new int[len];
    int i=1;
    int j=0;
    arr[0]=0;
    while(i<len)
    {
        if(s[i]==s[j])
        {
            arr[i]=j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=arr[j-1];
            }
            else
            {
                arr[i]=0;
                i++;
            }
        }
    }
    return arr;
}
int main()
{
    string s;
    cin>>s;
    int *arr=getLps(s);
    for(int i=0;i<s.length();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
