#include<stdio.h>
#include<stdlib.h>
struct Point{
	int x;
	int y;
}point[50000];
int cmp(const void *a, const void *b)
{
	struct Point x,y;
	x=*(struct Point *)a;
	y=*(struct Point *)b;
	if (x.x<y.x)
		return 1;
	else if (x.x>y.x)
		return -1;
	else if (x.y<y.y)
		return 1;
	else if (x.y>y.y)
		return -1;
	else return 0;
}
int main()
{
	int i,j,k,n,s;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%d%d",&point[i].x,&point[i].y);
		qsort(point,n,sizeof(point[0]),cmp);
		k=point[0].y;
		for (i=1,s=1;i<n;i++)
		{
			if (point[i].y>k)
			{
				k=point[i].y;
				s++;
			}
		}
		printf("%d\n",s);
		scanf("%d",&n);
	}
	return 0;
}
