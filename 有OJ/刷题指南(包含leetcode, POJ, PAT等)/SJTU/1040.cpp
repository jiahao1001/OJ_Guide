#include <cstdio>
int main()
{
    int n,i,t;
    scanf("%d",&n);
    int *num=new int[n];
    int* sons[2];
    sons[0]=new int[n];
    sons[1]=new int[n];
    int *queue=new int[n];
    for (i=0;i<n;++i) num[i]=0;
    for (i=1;i<n;++i)
    {
        scanf("%d",&t);
        sons[num[t]++][t]=i;
    }
    int head=0,tail=1,j;
    queue[0]=0;
    while (head<tail)
    {
        printf("%d ",queue[head]);
        for (j=0;j<num[queue[head]];++j) queue[tail++]=sons[j][queue[head]];
        ++head;
    }
    delete [] num;
    delete [] sons[0];
    delete [] sons[1];
    delete [] queue;
}
