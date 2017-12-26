#include<stdio.h>
#include<stdlib.h>
int position[1000];
int cmp(const void *a,const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (x<y)
		return -1;
	else if (x>y)
		return 1;
	else return 0;
}
int main()
{
	int i,j,n,r,num;
	scanf("%d%d",&r,&n);
	while (r!=-1 || n!=-1)
	{
		for (i=0;i<n;i++)
			scanf("%d",&position[i]);
		qsort(position,n,sizeof(position[0]),cmp);
		num=0;
		for (i=0;i<n;)
		{
			for (j=i+1;j<n;j++)
			{
				if (position[j]-position[i]>r)
					break;
			}
			i=j-1;
			num++;
			for (j=i+1;j<n;j++)
			{
				if (position[j]-position[i]>r)
					break;
			}
			i=j;
		}
		printf("%d\n",num);
		scanf("%d%d",&r,&n);
	}
	return 0;
}
