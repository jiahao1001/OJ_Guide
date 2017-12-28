#include<stdio.h>
int main()
{
	int road[1001];
	int n,i,j,in,max=0;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		road[i]=10001;
		scanf("%d",&in);
		for (j=0;road[j]<in;j++);
		road[j]=in;
		if (max<j+1)
			max=j+1;
	}
	printf("%d\n",max);
	return 0;
}
