/*You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration.
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 */
#include<bits/stdc++.h>
using namespace std;
int board[11][11];
bool check(int row,int col,int n)
{
    for(int i=col-1;i>=0;i--)
        if(board[row][i]==1)
        return false;
    for(int i=row-1;i>=0;i--)
        if(board[i][col]==1)
        return false;
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
        if(board[i][j]==1)
        return false;
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
        if(board[i][j]==1)
        return false;
    return true;
}
void queen_helper(int n,int row)
{
    if(row==n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
            cout<<endl;
            return;
    }
    for(int i=0;i<n;i++)
    {
        if(check(row,i,n))
        { board[row][i]=1;
            queen_helper(n,row+1);
            board[row][i]=0;
        }
    }
    return;
}

void N_queens(int n)
{
    memset(board,0,sizeof(board));
    queen_helper(n,0);
}
int main()
{
    N_queens(4);
}
