#include<bits/stdc++.h>
using namespace std;
void update(int index,int value,int *BIT,int n)
{
    for(;index<=n;index+=index&(-1*index))
    BIT[index]+=value;
}
int query(int index,int *BIT)
{int sum=0;
    for(;index>0;index-=index&(-1*index))
    sum+=BIT[index];
   return sum;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int [n+1]();
    int *BIT=new int [n+1]();
    for(int i=1;i<=n;i++)
       {cin>>arr[i];
         update(i,arr[i],BIT,n);
       }
  //  for(int i=0;i<=n;i++)
    //    cout<<BIT[i]<<" ";
      cout<<"sum of all element "<<query(n,BIT)<<endl;



}
