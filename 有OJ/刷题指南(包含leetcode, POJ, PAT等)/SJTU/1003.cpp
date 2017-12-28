#include <stdio.h>
#include <queue>
int l;
using namespace std;
bool in(int x,int y)
{
    return (x>=0 && x<l && y>=0 && y<l);
}
int main()
{
    int i,j,max=1;
    int data[100][100];
    queue<int> q;
    scanf("%d",&l);
    for (i=0;i<l;++i) for (j=0;j<l;++j)
    {
        scanf("%d",&data[i][j]);
        if (data[i][j]==2) data[i][j]=-1;
        else if (data[i][j]==1) q.push(i*l+j);
    }
    while (!q.empty())
    {
        i=q.front()/l;
        j=q.front()%l;
        if (in(i-1,j) && data[i-1][j]==0)
        {
            q.push((i-1)*l+j);
            data[i-1][j]=data[i][j]+1;
            if (data[i-1][j]>max) max=data[i-1][j];
        }
        if (in(i,j-1) && data[i][j-1]==0)
        {
            q.push(i*l+j-1);
            data[i][j-1]=data[i][j]+1;
            if (data[i][j-1]>max) max=data[i][j-1];
        }
        if (in(i+1,j) && data[i+1][j]==0)
        {
            q.push((i+1)*l+j);
            data[i+1][j]=data[i][j]+1;
            if (data[i+1][j]>max) max=data[i+1][j];
        }
        if (in(i,j+1) && data[i][j+1]==0)
        {
            q.push(i*l+j+1);
            data[i][j+1]=data[i][j]+1;
            if (data[i][j+1]>max) max=data[i][j+1];
        }
        q.pop();
    }
    printf("%d",max-1);
}
