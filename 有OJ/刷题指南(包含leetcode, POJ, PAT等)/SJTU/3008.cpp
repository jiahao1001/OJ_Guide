#include <iostream>
#include <queue>
using namespace std;
int n,m,x1,y1,x2,y2;
char map[101][101];
int data[101][101]={0};
bool in(int x,int y)
{
    return (1<=x && x<=n && 0<=y && y<m);
}
int main()
{
    cin>>n>>m>>x1>>y1>>x2>>y2;
    --y1;--y2;
    int i,j,k,x,y;
    for (i=1;i<=n;++i) cin>>map[i];
    queue<int> qx,qy;
    qx.push(x1);
    qy.push(y1);
    data[x1][y1]=1;
    while (!qx.empty())
    {
        x=qx.front();
        y=qy.front();
        qx.pop();
        qy.pop();
        if (x==x2 && y==y2)
        {
            cout<<data[x][y]-1<<'\n';
            return 0;
        }
        if (in(x-1,y) && map[x][y]!='-' && map[x-1][y]!='-' && map[x-1][y]!='*' && data[x-1][y]==0)
        {
            data[x-1][y]=data[x][y]+1;
            qx.push(x-1);
            qy.push(y);
        }
        if (in(x,y-1) && map[x][y]!='|' && map[x][y-1]!='|' && map[x][y-1]!='*' && data[x][y-1]==0)
        {
            data[x][y-1]=data[x][y]+1;
            qx.push(x);
            qy.push(y-1);
        }
        if (in(x+1,y) && map[x][y]!='-' && map[x+1][y]!='-' && map[x+1][y]!='*' && data[x+1][y]==0)
        {
            data[x+1][y]=data[x][y]+1;
            qx.push(x+1);
            qy.push(y);
        }
        if (in(x,y+1) && map[x][y]!='|' && map[x][y+1]!='|' && map[x][y+1]!='*' && data[x][y+1]==0)
        {
            data[x][y+1]=data[x][y]+1;
            qx.push(x);
            qy.push(y+1);
        }
    }
    cout<<"-1\n";
}
