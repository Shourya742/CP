#include<bits/stdc++.h>
using namespace std;
class triplet{
public:
int x,y,gcd;} ;
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
    ans.x= output.y;
    ans.y=output.x-(a/b)*output.y;
    ans.gcd=output.gcd;
    return ans;
}
int main()
{ int a,b;
cin>>a>>b;
triplet ans=Extended(a,b);
cout<<ans.gcd <<" "<<ans.x<<" "<<ans.y;


}
