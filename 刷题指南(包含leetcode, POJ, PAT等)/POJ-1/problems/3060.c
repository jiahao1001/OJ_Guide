#include<stdio.h>
#include<string.h>
int same[1000][1000];
int main()
{
	int dx[1000],dy[1000],x,y,i,j,k,d,n,t,min;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		memset(dx,0,sizeof(dx));
		memset(dy,0,sizeof(dy));
		memset(same,0,sizeof(same));
		scanf("%d%d",&d,&n);
		for (j=0;j<n;j++)
		{
			scanf("%d%d",&x,&y);
			x+=1000000000;
			y+=1000000000;
			x=x%d;
			y=y%d;
			same[x][y]++;
			dx[x]++;
			dy[y]++;
		}
		min=n;
		for (j=0;j<d;j++)
		{
			for (k=0;k<d;k++)
				if ((x=dx[j]+dy[k]-same[j][k])<min)
					min=x;
		}
		printf("%d\n",min);
	}
	return 0;
}
