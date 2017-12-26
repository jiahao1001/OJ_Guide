#include<stdio.h>
#include<stdlib.h>
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
	int i,j,k,n,t,sum,f[1000];
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		scanf("%d%d",&sum,&n);
		for (j=0;j<n;j++)
			scanf("%d",&f[j]);
		qsort(f,n,sizeof(f[0]),cmp);
		for (j=0,k=0;j<n;j++)
		{
			k+=f[j];
			if (k>=sum)
				break;
		}
		printf("Scenario #%d:\n",i);
		if (j==n)
			printf("impossible\n\n");
		else printf("%d\n\n",j+1);
	}
	return 0;
}
