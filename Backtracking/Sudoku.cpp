/*Adam likes to solve mathematical puzzles and riddles. He is quite good in them. But he is new to Sudoku, he never solved it before. Adam needs your help to solve Sudoku.

Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and sub grid of size 3×3 contains exactly one instance of the digits from 1 to 9.

Input
Input contains 9 lines of 9 space separated digits from 0 to 9(0 denotes an empty space).

Output
Output contains 9 lines of 9 space separated digits from 1 to 9 which represent solution of Sudoku.

Constraints
Already mentioned above

Example
Input:
  3 0 6 5 0 8 4 0 0
  5 2 0 0 0 0 0 0 0
  0 8 7 0 0 0 0 3 1
  0 0 3 0 1 0 0 8 0
  9 0 0 8 6 3 0 0 5
  0 5 0 0 9 0 6 0 0
  1 3 0 0 0 0 2 5 0
  0 0 0 0 0 0 0 7 4
  0 0 5 2 0 6 3 0 0


Output:
  3 1 6 5 7 8 4 9 2
  5 2 9 1 3 4 7 6 8
  4 8 7 6 2 9 5 3 1
  2 6 3 4 1 5 9 8 7
  9 7 4 8 6 3 1 2 5
  8 5 1 7 9 2 6 4 3
  1 3 8 9 4 7 2 5 6
  6 9 2 3 5 1 8 7 4
  7 4 5 2 8 6 3 1 9
*/
#include<bits/stdc++.h>
using namespace std;
#define n 9
bool issafe(int **grid,int row,int col,int no)
{
    for(int i=0;i<n;i++)
        if(grid[row][i]==no || grid[i][col]==no)
         return false;
    int rowf=row-row%3;
    int colf=col-col%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        if(grid[rowf+i][colf+j]==no)
        return false;
    return true;
}
bool findpos(int **grid,int& row,int& col)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(grid[i][j]==0)
    {
        row=i;
        col=j;
        return true;
    }
    return false;
}
bool solvesudoku(int **grid)
{int row,col;
    if(!findpos(grid,row,col))
        return true;
    for(int i=1;i<=9;i++)
    {
        if(issafe(grid,row,col,i))
        {
            grid[row][col]=i;
            if(solvesudoku(grid))
                return true;
            grid[row][col]=0;

        }
    }
    return false;
}
int main()
{ int **grid=new int*[n];
  for(int i=0;i<n;i++)
  {
      grid[i]=new int[n];
      for(int j=0;j<n;j++)
        cin>>grid[i][j];
  }
  solvesudoku(grid);
  for(int i=0;i<n;i++)
  {for(int j=0;j<n;j++)
    cout<<grid[i][j]<<" ";
    cout<<endl;}

}
