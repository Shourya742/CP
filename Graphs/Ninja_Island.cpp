/*Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1*/
#include<bits/stdc++.h>
using namespace std;
void initialize(bool** visitor,int n,int m)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        visitor[i][j]=false;
}
bool find(char** input,bool** visitor,char* word,int n,int m,int i,int j)
{
    if(input[i][j]=='A')
        return true;
     visitor[i][j]=true;
    bool ans=false;
    if(i-1>=0 &&j-1>=0 && input[i-1][j-1]==word[0] && !visitor[i-1][j-1])
        ans=find(input,visitor,word+1,n,m,i-1,j-1);
        if(i-1>=0 &&j>=0 && input[i-1][j]==word[0] && !visitor[i-1][j])
        ans=find(input,visitor,word+1,n,m,i-1,j);
            if(i-1>=0 &&j+1<m && input[i-1][j+1]==word[0] && !visitor[i-1][j+1])
        ans=find(input,visitor,word+1,n,m,i-1,j+1);
            if(i>=0 &&j-1>=0 && input[i][j-1]==word[0] && !visitor[i][j-1])
        ans=find(input,visitor,word+1,n,m,i,j-1);
            if(i>=0 &&j+1<m && input[i][j+1]==word[0] && !visitor[i][j+1])
        ans=find(input,visitor,word+1,n,m,i,j+1);
            if(i+1<n &&j+1<m && input[i+1][j+1]==word[0] && !visitor[i+1][j+1])
        ans=find(input,visitor,word+1,n,m,i+1,j+1);
            if(i+1<n &&j>=0 && input[i+1][j]==word[0] && !visitor[i+1][j])
        ans=find(input,visitor,word+1,n,m,i+1,j);
            if(i+1<n &&j-1>=0 && input[i+1][j-1]==word[0] && !visitor[i+1][j-1])
        ans=find(input,visitor,word+1,n,m,i+1,j-1);

return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    char **input=new char*[n];
    for(int i=0;i<n;i++)
    {
        input[i]=new char[m];
        for(int j=0;j<m;j++)
            cin>>input[i][j];
    }
    char word[]="CODINGNINJA";
    bool **visitor=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visitor[i]=new bool[m];
    }
    initialize(visitor,n,m);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        { if(input[i][j]=='C')
          {bool a=false;
              a=find(input,visitor,word+1,n,m,i,j);
            if(a)
                ans++;
          }
            initialize(visitor,n,m);
        }
    }
    cout<<ans<<endl;
}
