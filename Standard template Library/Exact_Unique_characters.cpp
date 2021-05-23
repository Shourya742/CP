/*Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string s2;
    set<char> s1;
    for(int i=0;i<s.length();i++)
        if(s1.find(s[i])==s1.end())
    {  s2+=s[i];
       s1.insert(s[i]);

    }
    cout<<s2<<endl;
}
