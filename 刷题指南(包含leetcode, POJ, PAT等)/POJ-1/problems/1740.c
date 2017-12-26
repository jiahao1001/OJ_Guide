#include<stdio.h>
int main()
{
	int n,i,j,k,d[10],f[10],q;
	scanf("%d",&n);
	while (n!=0)
	{
		j=0;
		q=0;
		for (i=0;i<n;i++)
		{
			f[i]=1;
			scanf("%d",&k);
			for (j=0;j<q;j++)
			{
				if (d[j]==k)
				{
					f[j]++;
					break;
				}
			}
			if (j==q)
				d[q++]=k;
		}
		for (i=0,j=0;i<q;i++)
			if (f[i]%2!=0)
				j++;
		if (j==0)
			printf("0\n");
		else printf("1\n");
		scanf("%d",&n);
	}
	return 0;
}
