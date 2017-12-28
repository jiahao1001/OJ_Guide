#include <stdio.h>
void qsort(int* t,int l,int r)
{
    if (l>=r) return;
    int i=l,j=r,v=t[i];
    while (i<j)
    {
        while ((i<j)&&(t[j]>=v)) --j;
        t[i]=t[j];
        while ((i<j)&&(t[i]<=v)) ++i;
        t[j]=t[i];
    }
    t[i]=v;
    qsort(t,l,i-1);
    qsort(t,i+1,r);
}
int main()
{
    //FILE *fp=fopen("1348.in","r");
    int n,m,i,x;
    int sum=0,t,y;
    scanf("%d",&n);
    int *songs=new int[n];
    for (i=0;i<n;++i)
    {
        scanf("%d",&t);
        songs[i]=sum;
        sum+=t;
    }
    scanf("%d",&m);
    int* dancers[2];
    dancers[0]=new int[m/2];
    dancers[1]=new int[m/2];
    int num[2]={0,0};
    for (i=0;i<m;++i)
    {
        scanf("%d %d",&x,&y);
        dancers[x-1][num[x-1]++]=y;
    }
    m/=2;
    qsort(dancers[0],0,m-1);
    qsort(dancers[1],0,m-1);
    i=0;
    x=0;
    double wait[2]={0,0};
    while (i<n)
    {
        while (x<m && dancers[0][x]<=songs[i] && dancers[1][x]<=songs[i])
        {
            //printf("%d %d %d\n",songs[i],dancers[0][x],dancers[1][x]);
            wait[0]+=(songs[i]-dancers[0][x])/double(m);
            wait[1]+=(songs[i]-dancers[1][x])/double(m);
            //printf("%d %d %d %d\n",i,x,wait[0],wait[1]);
            ++x;
        }
        ++i;
    }
/*
    for (i=0;i<n;++i) printf("%d ",songs[i]);
    printf("\n");
    for (i=0;i<m;++i) printf("%d ",dancers[0][i]);
    printf("\n");
    for (i=0;i<m;++i) printf("%d ",dancers[1][i]);
    printf("\n");
*/
    printf("%0.2f %0.2f",wait[0],wait[1]);
    delete [] songs;
    delete [] dancers[0];
    delete [] dancers[1];
}
