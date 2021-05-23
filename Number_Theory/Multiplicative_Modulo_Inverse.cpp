#include<bits/stdc++.h>
using namespace std;
class triplet{public :
    int x,y,gcd;};
triplet Extended(int a,int b)
{

    if(b==0)
    {

        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet output=Extended(b,a%b);
    triplet ans;
    ans.x=output.y;
    ans.y=output.x-(a/b)*output.y;
    ans.gcd=output.gcd;
    return ans;

}
int mmInverse(int a,int m)
{
    triplet ans=Extended(a,m);
    return ans.x;
}
int main()
{
    int a,m;
    cin>>a>>m;
    cout<<mmInverse(a,m)<<endl;
}
