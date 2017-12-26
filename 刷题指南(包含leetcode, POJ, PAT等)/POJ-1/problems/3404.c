#include<stdio.h>
#include<stdlib.h>
int speed[100],n;
int cmp(const void *a, const void *b)
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
	int i,s;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&speed[i]);
	qsort(speed,n,sizeof(speed[0]),cmp);
	s=0;
	while (n>=4)
	{
		n-=2;
		if (speed[0]+speed[n]>speed[1]+speed[1])
			s+=speed[0]+speed[1]+speed[1]+speed[n+1];
		else s+=speed[0]+speed[0]+speed[n]+speed[n+1];
	}
	if (n==3)
		s+=speed[0]+speed[1]+speed[2];
	else if (n==2)
		s+=speed[1];
	else s+=speed[0];
	printf("%d\n",s);
	return 0;
}
