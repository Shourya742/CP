/*
Chef has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'.
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA*/
#include<bits/stdc++.h>
using namespace std;
bool issafe(char** grid,string s,int row,int col)
{
    int n=s.length();
    for(int i)

}
bool findpos(char** grid,int &row,int &col)
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        if(grid[i][j]=='-')
    {
        row=i;
        col=j;
        return true;
    }
    return false;
}
bool crossword(char **grid,string input[])
{ int row,col;
    if(!findpos(grid,row,col))
        return true;
    for(int i=0;i<input.size();i++)
    { if(issafe(grid,input[i],row,col))
      {
          if(crossword(grid,input))
            return true;
      }

    }
    return false;
}
int main()
{
    char **grid=new char*[10];
    for(int i=0;i<11;i++)
    {
        grid[i]=new char[10];
        for(int j=0;j<10;j++)
        cin>>grid[i][j]

        }
    string s;
    cin>>s;
    string input[10000];
    int i=0,k=0;
    while(i<s.length())
    {
        string s1;
        if(s[i]!=';')
        s1+=s[i]
        else
        {
            input[k]=s1;
            k++;
            s1.clear();
        }
        i++;
    }
    input[k]=s1;
     crossword(grid,input);

}
