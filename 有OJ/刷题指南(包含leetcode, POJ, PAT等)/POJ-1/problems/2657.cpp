#include<iostream>
int main()
{
	int i,j,k,l,n,m,z,a,b,qu[1000]={0};
    scanf("%d%d%d",&n,&z,&m);
	for (i=0;i<m;i++)
	{
		scanf("%d",&j);
		qu[i]=j;
	}
	for (i=1;i<z;i++)
	{
		for (j=0;j<i;j++)
		{
			k=j*n;
			if ((k+z-1)%i!=0)
				continue;
			for (a=0;a<j;a++)
			{
				b=a*n;
				for (l=0;l<m;l++)
					if ((b+qu[l]-1)%i==0)
						break;
				if (l<m)
					break;
			}
			if (a==j)
			{
				for (l=0;l<m;l++)
					if (qu[l]<z && (k+qu[l]-1)%i==0)
						break;
				if (l==m)
				{
					printf("%d\n",i);
					return 0;
				}
			}
		}
	}
	return 0;
}
