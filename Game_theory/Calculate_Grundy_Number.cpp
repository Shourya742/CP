/*Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
Input Format
An Integer 'n'
Output Format
Grundy Number(n)
Sample Input 1 -
10
Sample Output 1-
0
*/
#include<bits/stdc++.h>
using namespace std;
int Mex(unordered_set<int> s)
{

    int mex=0;
    while(s.find(mex)!=s.end())
        mex++;
    return mex;
}
int grundy(int n)
{

    if(n==0)
        return 0;
    unordered_set<int> s;
    s.insert(grundy(n/6));
    s.insert(grundy(n/3));
    s.insert(grundy(n/2));
    int mex=Mex(s);
    return mex;
}
int main()
{

    int n;
    cin>>n;
    cout<<grundy(n);
}
