#include <stdio.h>
#include <queue>
using namespace std;
int n,m;
int map[500][500];
bool in(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<m);
}
void paint(int x,int y,int n)
{
    queue<int> qx,qy;
    qx.push(x);
    qy.push(y);
    map[x][y]=n;
    while (!qx.empty())
    {
        x=qx.front();
        y=qy.front();
        qx.pop();
        qy.pop();
        if (in(x-1,y)&& map[x-1][y]==0)
        {
            map[x-1][y]=n;
            qx.push(x-1);
            qy.push(y);
        }
        if (in(x+1,y)&& map[x+1][y]==0)
        {
            map[x+1][y]=n;
            qx.push(x+1);
            qy.push(y);
        }
        if (in(x,y-1)&& map[x][y-1]==0)
        {
            map[x][y-1]=n;
            qx.push(x);
            qy.push(y-1);
        }
        if (in(x,y+1)&& map[x][y+1]==0)
        {
            map[x][y+1]=n;
            qx.push(x);
            qy.push(y+1);
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    int i,j,t=0;
    for (i=0;i<500;++i) for (j=0;j<500;++j) map[i][j]=-1;
    for (i=0;i<n;++i) for (j=0;j<m;++j) scanf("%d",&map[i][j]);
    for (i=0;i<n;++i) for (j=0;j<m;++j) if (map[i][j]==0) paint(i,j,++t);
    printf("%d\n",t);
}
