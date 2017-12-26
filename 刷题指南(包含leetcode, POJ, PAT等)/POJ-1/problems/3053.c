#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int p[100],q[100],bowling[100][1000];
int cmp(const void *a,const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (x<y)
		return 1;
	else if (x>y)
		return -1;
	else return 0;
}
int main()
{
	int i,j,k,l,max,min,t,m,n;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d%d",&n,&m);
		for (j=0;j<n;j++)
		{
			for (k=0;k<m;k++)
				scanf("%d",&bowling[j][k]);
			qsort(bowling[j],m,sizeof(bowling[j][0]),cmp);
		}
		for (j=0;j<n;j++)
		{
			memset(p,0,sizeof(p));
			memset(q,0,sizeof(q));
			min=0;
			max=0;
			for (k=0;k<m;k++)
			{
				for (l=0;l<n;l++)
				{
					if (l!=j && q[l]<m && bowling[j][k]<=bowling[l][q[l]])
					{
						q[l]++;
						break;
					}
				}
				if (l==n)
					min++;
				for (l=0;l<n;l++)
				{
					if (l==j)
						continue;
					while (p[l]<m && bowling[j][k]<=bowling[l][p[l]])
						p[l]++;
					if (p[l]==m)
						break;
					p[l]++;
				}
				if (l==n)
					max++;
			}
			printf("%d %d\n",min,max);
		}
	}
	return 0;
}
