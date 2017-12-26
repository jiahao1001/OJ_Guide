#include<stdio.h>
int main()
{
	int t,x,m,d,s,min=1000000,i,j;
	scanf("%d%d%d",&t,&x,&m);
	for (i=0;i<m;i++)
	{
		scanf("%d%d",&d,&s);
		j=d/s;
		if (d%s==0)
			j--;
		if (j<min)
			min=j;
	}
	if (min<1)
		i=0;
	else if (min>t)
		i=t*x;
	else i=min*x+(t-min)/2*x;
	printf("%d\n",i);
	return 0;
}
