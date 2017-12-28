#include<stdio.h>
int main()
{
	int n,m,i,j,k,t;
	short p[10001],q[10001];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&m);
		for (j=1;j<=m;j++)
		{
			scanf("%d",&p[j]);
			q[p[j]]=j;
		}
		t=0;
		for (j=1;j<=m;j++)
		{
			if (p[j]!=j)
			{
				t++;
				p[q[j]]=p[j];
				q[p[j]]=q[j];
			}
		}
		printf("%d\n",t);
	}
	return 0;
}
