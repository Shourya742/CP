/*You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.
Output
Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
Constraints
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11
Sample Input
3 3
1 1 1
2 2 2
3 1 5
Sample Output
3*/

#include<bits/stdc++.h>
using namespace std;
struct paint{long long start,pace,cost;};
bool compare(paint a1,paint a2)
{   return a1.start<a2.start;
}

bool compare2(paint a1,paint a2)
{if(a1.start==a2.start)
{//if(((double)a1.cost/a1.pace)!=((double)a2.cost/a2.pace))
   // return ((double)a1.cost/a1.pace)<((double)a2.cost/a2.pace);
if(a1.pace==a2.pace)
    return a1.cost<a2.cost;
    return a1.pace>a2.pace;
}
    return a1.start<a2.start;
}


int main()
{
    long long n,d;
    cin>>n>>d;
    paint arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].start>>arr[i].cost>>arr[i].pace;
    //int **dp=new int*[n+1];
    //for(int i=0;i<n;i++)
      //  dp[i]=new int[d+1]();
        sort(arr,arr+n,compare);
    //    for(int i=0;i<n;i++)
    //{
     //cout<<arr[i].start<<" "<<arr[i].cost<<" "<<arr[i].pace<<endl;
    //}
        sort(arr,arr+n,compare2);
  //  for(int i=0;i<n;i++)
   // {
    //cout<<arr[i].start<<" "<<arr[i].cost<<" "<<arr[i].pace<<endl;
    //}
    long long time=arr[0].start;
    long long cash=arr[0].cost;
    long long pace=arr[0].pace;
    for(int i=1;i<n;i++)
    {int flag=0;
        if(arr[i].pace >pace && time!=arr[i].start)
        {
            if(d<pace*(arr[i].start-time))
            {flag=1;
            }
            else
            {d-=(pace)*(arr[i].start-time);
            {pace=arr[i].pace;
            time=arr[i].start;
            cash+=arr[i].cost;}}
        }
        if(flag)
            {cash-=arr[i].cost;
                break;}
//cout<<flag<<" "<<arr[i].pace<<" "<<d<<endl;
    }
    cout<<cash<<endl;
}
