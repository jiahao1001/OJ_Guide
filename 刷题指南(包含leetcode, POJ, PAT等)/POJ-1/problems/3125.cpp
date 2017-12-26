#include<stdio.h>
int queue[200];
bool print[200];
int find(int n)
{
	int i,j;
	for (i=1,j=0;i<n;i++)
		if (queue[i]>queue[j])
			j=i;
	return j;
}
int main()
{
	int t,test,i,j,k,l,m,n;
	scanf("%d",&test);
	for (t=0;t<test;t++)
	{
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
		{
			scanf("%d",&queue[i]);
			print[i]=false;
		}
		print[m]=true;
		l=queue[m];
		k=0;
		while (queue[(j=find(n))]!=l)
		{
			for (i=n;i<n+j;i++)
			{
				queue[i]=queue[i-n];
				print[i]=print[i-n];
			}
			for (i=0;i<n-1;i++)
			{
				queue[i]=queue[i+j+1];
				print[i]=print[i+j+1];
			}
			n--;
			k++;
		}
		for (i=0;i<n;i++)
		{
			if (queue[i]==l)
			{
				k++;
				if (print[i]==true)
					break;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}
