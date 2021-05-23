/*Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0
6 0 0 0 5 0 0 4 0
0 2 0 4 0 0 0 1 0
2 0 8 0 0 0 0 0 0
0 7 0 5 0 9 0 6 0
0 0 0 0 0 0 4 0 1
0 1 0 0 0 5 0 8 0
0 9 0 0 7 0 0 0 4
0 8 2 0 4 0 0 0 6
Sample Output :
true*/
#include<bits/stdc++.h>
using namespace std;
bool ifsafe(int **grid,int row,int col,int no)
{
    for(int i=0;i<9;i++)
    {
        if(grid[i][col]==no || grid[row][i]==no)
            return false;
    }
    int rowf=row-row%3;
    int colf=col-col%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
    {
        if(grid[i+rowf][j+colf]==no)
        return false;

    }
    return true;
}
bool findpos(int **grid,int &row,int &col)
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        if(grid[i][j]==0)
    {
        row=i;
        col=j;
        return true;
    }
    return false;
}
bool sudokusolver(int** grid)
{int row,col;
    if(!findpos(grid,row,col))
        return true;
    for(int i=1;i<10;i++)
    {
        if(ifsafe(grid,row,col,i))
        {
            grid[row][col]=i;
            if(sudokusolver(grid))
                return true;
            grid[row][col]=0;
        }
    }
    return false;
}
int main()
{
    int **grid=new int *[9];
    for(int i=0;i<9;i++)
    {
        grid[i]=new int[9];
        for(int j=0;j<9;j++)
            cin>>grid[i][j];
    }
    if(sudokusolver(grid))
        cout<<"True"<<endl;
    else
        cout<<"false"<<endl;
}
