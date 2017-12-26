#include <stdio.h>
int main()
{
	int f[2][100],i,j,n,d=0;
	scanf("%d\n%d",&n,&f[0][0]);
	for (i=1;i<n;i++)
	{
		d=1-d;
		scanf("%d",&f[d][0]);
		f[d][0]+=f[1-d][0];
		for (j=1;j<i;j++)
		{
			scanf("%d",&f[d][j]);
			f[d][j]+=(f[1-d][j-1] > f[1-d][j]) ? f[1-d][j-1] : f[1-d][j];
		}
		scanf("%d",&f[d][i]);
		f[d][i]+=f[1-d][i-1];
	}
	j=f[d][0];
	for (i=1;i<n;i++)
	{
		if (j<f[d][i])
			j=f[d][i];
	}
	printf("%d\n",j);
	return 0;
}
