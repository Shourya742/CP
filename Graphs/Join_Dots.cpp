/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 50
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1*/
#include<bits/stdc++.h>
using namespace std;
bool Find(char** board,int **visitor,int n,int m,int i,int j,int& k,int sv,int ev)
{  int ans=false;
k++;
    visitor[i][j]=board[i][j]-'A'+1;
    if(i-1>=0 && j>=0 && board[i-1][j]==board[i][j] && visitor[i-1][j]==0)
        ans=Find(board,visitor,n,m,i-1,j,k,sv,ev);
    if(i>=0 && j-1>=0 && board[i][j-1]==board[i][j] && visitor[i][j-1]==0)
        ans=Find(board,visitor,n,m,i,j-1,k,sv,ev);
    if(i+1<n && j>=0 && board[i+1][j]==board[i][j] && visitor[i+1][j]==0)
        ans=Find(board,visitor,n,m,i+1,j,k,sv,ev);
     if(i>=0 && j+1<m && board[i][j+1]==board[i][j] && visitor[i][j+1]==0)
        ans=Find(board,visitor,n,m,i,j+1,k,sv,ev);
      if(k>=4 && ((i-1==sv && j==ev)||(i==sv && j-1==ev)||(i+1==sv && j==ev)||(i==sv &&j+1==ev)))
        return true;


        return ans;

}
int main()
{
    int n,m;
    cin>>n>>m;
    char** board=new char* [n];
    for(int i=0;i<n;i++)
    {
        board[i]=new char[m];
        for(int j=0;j<m;j++)
            cin>>board[i][j];
    }
    int **visitor=new int*[n];
    for(int i=0;i<n;i++)
    {
        visitor[i]=new int[m]();
    }
    int count=0;
    bool ans=false;
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {  int k=0;
         if(visitor[i][j]==0)
         {
             ans=Find(board,visitor,n,m,i,j,k,i,j);
         }
         if(ans && k>=4)
            count++;
     }
 }
 cout<<count<<endl;
}
