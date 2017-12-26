#include<stdio.h>
#define MAX	200001
int Dist[MAX],n,k;
bool flag[MAX]={false};
void bfs()
{
	int queue[MAX]={n},front=0,rear=1,p;
	Dist[n]=0;
	flag[n]=true;
	while (front<rear)
	{
		p=queue[front];
		if (p==k)
			break;
		if (p>0 && flag[p-1]==false)
		{
			flag[p-1]=true;
			Dist[p-1]=Dist[p]+1;
			queue[rear++]=p-1;
		}
		if (p<k)
		{	
			if (flag[p+1]==false)
			{
				flag[p+1]=true;
				Dist[p+1]=Dist[p]+1;
				queue[rear++]=p+1;
			}
			if (flag[p+p]==false)
			{
				flag[p+p]=true;
				Dist[p+p]=Dist[p]+1;
				queue[rear++]=p+p;
			}
		}
		front++;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	bfs();
	printf("%d\n",Dist[k]);
	return 0;
}
