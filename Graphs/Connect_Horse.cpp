/*You all must be familiar with the chess-board having
8*8 squares of alternate black and white cells. Well, here
we have for you a similar
N*M size board with similar arrangement of black and white
cells.
A few of these cells have Horses placed over them.
Each horse is unique. Now these horses are not the
usual horses which could jump to any of the
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo
10^9+7
Input:
First line contains
T which is the number of test cases.
T test cases follow first line of each containing three integers
N, M and Q where
N,M is the size of the board and
Q is the number of horses on it.

Q lines follow each containing the 2 integers
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M*/
 #include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int ad[1003][1003];
int factorial[1000003];
int n,m;
int visit[1003][1003];
int dir [8][2] = { {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };
long long sol(int a, int b){
    visit[a][b] = 1;
    long long count =1;
    queue <pair<int ,int > > q;
    q.push(make_pair(a,b));
    while(!q.empty()){
        a = q.front().first;
        b = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int x = a + dir[i][0];
            int y = b + dir[i][1];
            if(x <= 0 || x > n || y <= 0 || y > m) continue;
            if(ad[x][y]==3 and !visit[x][y]){
                count++;
                q.push(make_pair(x,y));
                visit[x][y]=1;
            }


        }

    }
    return count;
}
void initialize(){
    for(int i=0;i<1003;i++){
        for(int j=0;j<1003;j++){
            ad[i][j]=1;
            visit[i][j]=0;
        }
    }
}
int main()
{
    int t,q;
    cin>>t;
    factorial[0] = 1;
    for(long long i = 1; i <= 1e6; i++){
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    while(t--){
        initialize();
        cin>>n>>m>>q;
        int x,y;
        while(q--){
            cin>>x>>y;
            ad[x][y] = 3;
        }
        long long c ;
        long long ans = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ad[i][j]==3 and !visit[i][j]){
                    c=sol(i,j);
                    ans = (ans*factorial[c])%MOD;
                }
            }
        }
        cout<<ans%MOD<<"\n";
    }
    return 0;
}
