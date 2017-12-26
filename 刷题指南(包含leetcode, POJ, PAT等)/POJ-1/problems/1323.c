#include<stdio.h>
#include<stdlib.h>
int card[50],n,m;
int cmp(const void *a, const void *b)
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
	int flag[1001],i,t=1,max,s;
	while (scanf("%d%d",&m,&n),m!=0 || n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%d",&card[i]);
		for (i=1;i<=n*m;i++)
			flag[i]=0;
		qsort(card,n,sizeof(card[0]),cmp);
		max=n*m;
		s=0;
		for (i=0;i<n;i++)
		{
			while (flag[max]==1)
				max--;
			if (max==card[i])
				s++;
			flag[max]=1;
			flag[card[i]]=1;
		}
		printf("Case %d: %d\n",t++,s);
	}
	return 0;
}
