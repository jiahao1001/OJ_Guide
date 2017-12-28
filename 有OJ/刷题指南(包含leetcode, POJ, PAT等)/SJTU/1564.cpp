#include <cstdio>
bool maze[6][6]={0};
int data[6][6];
int n,min,cost;
int x0,y0,x1,y1;
bool in(int x,int y)
{
    return (x>=0 && y>=0 && x<6 && y<6);
}
void dps(int x,int y,int state)
{
    //printf("%d %d\n",x,y);
    if (x==x1 && y==y1)
    {
        if (cost<min) min=cost;
        return;
    }
    maze[x][y]=true;
    if (in(x-1,y) && (!maze[x-1][y]))
    {
        cost+=state*data[x-1][y];
        dps(x-1,y,state*data[x-1][y]%4+1);
        cost-=state*data[x-1][y];
    }
    if (in(x,y-1) && (!maze[x][y-1]))
    {
        cost+=state*data[x][y-1];
        dps(x,y-1,state*data[x][y-1]%4+1);
        cost-=state*data[x][y-1];
    }
    if (in(x+1,y) && (!maze[x+1][y]))
    {
        cost+=state*data[x+1][y];
        dps(x+1,y,state*data[x+1][y]%4+1);
        cost-=state*data[x+1][y];
    }
    if (in(x,y+1) && (!maze[x][y+1]))
    {
        cost+=state*data[x][y+1];
        dps(x,y+1,state*data[x][y+1]%4+1);
        cost-=state*data[x][y+1];
    }
    maze[x][y]=false;
}
int test()
{
    int i,j;
    for (i=0;i<6;++i) for (j=0;j<6;++j)
    {
        scanf("%d",&data[i][j]);
        maze[i][j]=false;
    }
    scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
    cost=0;min=(1<<31)-1;
    dps(x0,y0,1);
    return min;
}
int main()
{
    freopen("1564.in","r",stdin);
    int n,i;
    scanf("%d",&n);
    for (i=0;i<n;++i) printf("%d\n",test());
}
