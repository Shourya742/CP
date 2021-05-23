/*You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
Input Format
Line 1 : Integer N
Next N Lines : Each line will contain ith row elements (separated by space)
Output Format :
One Line for every possible solution.
Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1
Sample Output 1 Explanation :
Only 1 path is possible
Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1
1 0 0 1 0 0 1 1 1
1 0 0 1 1 0 0 1 1
1 0 0 1 1 1 0 0 1
Sample Output 2 Explanation :
4 paths are possible*/
#include<bits/stdc++.h>
using namespace std;
void mazehelp(int **maze,int **solution,int n,int x,int y)
{
    if(x==n-1 && y==n-1)
    {
        solution[x][y]=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            cout<<solution[i][j]<<" ";
        cout<<endl;
        solution[x][y]=0;
        return;
    }
    if(x<0||x>n-1||y<0||y>n-1||solution[x][y]==1||maze[x][y]==0)
        return;
    solution[x][y]=1;
    mazehelp(maze,solution,n,x+1,y);
    mazehelp(maze,solution,n,x,y+1);
    mazehelp(maze,solution,n,x-1,y);
    mazehelp(maze,solution,n,x,y-1);
    solution[x][y]=0;

}
void Rat_in_maze(int **maze,int **solution,int n)
{
    mazehelp(maze,solution,n,0,0);
    return;
}
int main()
{
    int n;
    cin>>n;
    int **maze=new int*[n];
    for(int i=0;i<n;i++)
    {maze[i]=new int[n];
    for(int j=0;j<n;j++)
        cin>>maze[i][j];
    }
    int **solution=new int*[n];
    for(int i=0;i<n;i++)
        solution[i]=new int[n]();
    Rat_in_maze(maze,solution,n);
}
