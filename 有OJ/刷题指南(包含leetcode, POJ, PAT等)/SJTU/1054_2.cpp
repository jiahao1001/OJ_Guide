#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100010
int sons[MAXN][2];
int father[MAXN],size[MAXN],data[MAXN];
int spt=0,spttail=0,tot=0,men=0;
void rotate(int x,int w) //rotate(node,0/1)
{
    int y=father[x];
    sons[y][1-w]=sons[x][w];
    if (sons[x][w]) father[sons[x][w]]=y;
    father[x]=father[y];
    if (father[y])
    if (y==sons[father[y]][0]) sons[father[y]][0]=x;
    else sons[father[y]][1]=x;
    sons[x][w]=y;
    father[y]=x;
    size[x]=size[y];
    size[y]=size[sons[y][0]]+size[sons[y][1]]+1;
}
void splay(int x,int y) //splay(node,position)
{
    if (!x) return ;
    while(father[x]!=y)
    {
        if (father[father[x]]==y)
            if (x==sons[father[x]][0]) rotate(x,1);
            else rotate(x,0);
        else
            if (father[x]==sons[father[father[x]]][0])
                if (x==sons[father[x]][0])
                {
                    rotate(father[x],1);
                    rotate(x,1);
                } else
                {
                    rotate(x,0);
                    rotate(x,1);
                }
            else
                if (x==sons[father[x]][1])
                {
                    rotate(father[x],0);
                    rotate(x,0);
                } else
                {
                    rotate(x,1);
                    rotate(x,0);
                }
    }
    if (!y) spt=x;
}
void search(int x,int w)
{
    while(data[x]!=w)
    {
        if (w<data[x])
        {
            if (sons[x][0]) x=sons[x][0];
            else break;
        } else if (w>data[x])
        {
            if (sons[x][1]) x=sons[x][1];
            else break;
        }
    }
    splay(x,0);
}
void insert(int w) //insert(value)
{
    spttail++;
    data[spttail]=w;
    size[spttail]=1;
    sons[spttail][0]=0;
    sons[spttail][1]=0;
    if (!spt)
    {
        father[spttail]=0;
        spt=spttail;
    } else
    {
        int x=spt;
        while(1)
        {
            size[x]++;
            if (w<data[x])
                if (sons[x][0]) x=sons[x][0];
                else break;
            else
                if (sons[x][1]) x=sons[x][1];
                else break;
        }
        father[spttail]=x;
        if (w<data[x]) sons[x][0]=spttail;
        else sons[x][1]=spttail;
        splay(spttail,0);
    }
}
void select(int x,int v) //select(root,k)
{
    while(v!=size[sons[x][0]]+1)
    {
        if (v<=size[sons[x][0]]) x=sons[x][0];
        else
        {
            v-=size[sons[x][0]]+1;
            x=sons[x][1];
        }
    }
    splay(x,0);
}
int main()
{
    freopen("1054.in","r",stdin);

    int n,mi;
    scanf("%d%d",&n,&mi);
    spt=0;
    spttail=0;
    tot=0;
    men=0;
    for (int i=1;i<=n;i++)
    {
        char c;
        c=getchar();
        while(c!='I'&&c!='A'&&c!='S'&&c!='F') c=getchar();
        int k;
        scanf("%d",&k);
        if (c=='I')
        {
            if (k>=mi) insert(k-tot);
        } else
        if (c=='A')
        {
            tot+=k;
        } else
        if (c=='S')
        {
            tot-=k;
            search(spt,mi-tot-1);
            if (data[spt]!=mi-tot-1)
            {
                insert(mi-tot-1);
                men+=size[sons[spt][0]];
                spt=sons[spt][1];
                father[spt]=0;
            } else
            {
                men+=size[sons[spt][0]]+1;
                spt=sons[spt][1];
                father[spt]=0;
                search(spt,mi-tot-1);
                while(data[spt]==mi-tot-1)
                {
                    men++;
                    spt=sons[spt][1];
                    father[spt]=0;
                    search(spt,mi-tot-1);
                }
            }
        } else
        {
            if (k>size[spt]) printf("-1\n");
            else
            {
                select(spt,size[spt]-k+1);
                printf("%d\n",data[spt]+tot);
            }
        }
        //printf("Size:%d mi-tot+1:%d\n",size[spt],mi-tot); //debug
    }
    //printf("%d\n",men-size[spt]);
    printf("%d\n",men);
    return 0;
}
