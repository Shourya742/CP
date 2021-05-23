/*In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems. Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, the one with less roll number will have higher rank. The input is provided in order of roll number.
Input Format:
First line will have a single integer ‘n’, denoting the number of students in the class.
Next ‘n’ lines each will have one string denoting the name of student and three space separated integers m1, m2, m3 denoting the marks in three subjects.
Output Format:
Print ‘n’ lines having two values: First, the position of student in the class and second his name.
Constraints:
1 <= n <= 10^5
0 <= m1, m2, m3 <= 100
Sample Input:
3
Mohit 94 85 97
Shubham 93 91 94
Rishabh 95 81 99
Sample Output:
1 Shubham
2 Mohit
3 Rishabh*/
#include<bits/stdc++.h>
using namespace std;
struct stu{
string name;
int m1,m2,m3,total,roll;};
bool com(stu s1,stu s2)
{ if(s1.total==s2.total)
   return s1.roll<s2.roll;
    return s1.total>s2.total;
}
int main()
{
    int n;
    cin>>n;
    stu arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].name;
        cin>>arr[i].m1>>arr[i].m2>>arr[i].m3;
        arr[i].total=arr[i].m1+arr[i].m2+arr[i].m3;
        arr[i].roll=i+1;
    }
    sort(arr,arr+n,com);
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<arr[i].name<<endl;
    }
}
