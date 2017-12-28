#include <stdio.h>
int num[200002],n,N;
int diff(int i)
{
	return (i+n)%N;
}
int root(int i)
{
	int k,j=i;
	while (num[j]!=j)
		j=num[j];
	while (i!=j)
	{
		k=num[i];
		num[i]=j;
		i=k;
	}
	return j;
}
int main()
{
	int a,c,d,m,t,i,j;
	char ch;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		N=2*n;
		for (a=0;a<N;a++) 
			num[a]=a;
		for (a=0;a<m;a++)
		{
			getchar();
			scanf("%c%d%d",&ch,&c,&d);
			if (ch=='A')
			{	
				i=root(c);
				j=root(d);
				if (i%n!=j%n) 
					printf("Not sure yet.\n");
				else 
				{
					if (i==j)
						printf("In the same gang.\n");
					else printf("In different gangs.\n");
				}
			}
			else
			{
				i=root(diff(c));
				j=root(d);
				num[i]=j;
				num[diff(i)]=diff(j);
			}
		}
	}
	return 0;
}
