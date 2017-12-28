#include <iostream>
#include <cstdio>
using namespace std;
int xpos[100000];
int ypos[100000];
int qx[10000];
int qy[10000];
int qz[10000];
int n,m;
inline void exchange(int &x,int &y)
{
    int tmp;
    tmp=x;
    x=y;
    y=tmp;
}
inline int Find(int x,int y)
{

    for(int i=0;i<n;i++)
        if((qx[i]==x)&&(qy[i]==y))
            return qz[i];
    return 0;
}
int main()
{
    for(int i=0;i<100000;i++)
        xpos[i]=ypos[i]=i;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",&qx[i],&qy[i],&qz[i]);
    int tmpx,tmpy;
    int op;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&op,&tmpx,&tmpy);
        if(op==0)
            exchange(xpos[tmpx],xpos[tmpy]);
        else if(op==1)
            exchange(ypos[tmpx],ypos[tmpy]);
        else
            printf("%d\n",Find(xpos[tmpx],ypos[tmpy]));
    }

}
