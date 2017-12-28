#include<stdio.h>
#include<string.h>
int k,n,p[8192];
char f[4097]={0};
int find(int x)
{
	int y,i,j,r=2*n,t=1;
	p[0]=x;
	f[x]=1;
	for (i=1;i<r;i++)
	{
		y=(i-1)/2;
		if (t==1)
			p[i]=p[y];
		else{
			j=p[y]-k;
			if (j<1)
				j=1;
			while (j<=n && f[j]==1)
				j++;
			if (j>n)
				return 0;
			p[i]=j;
			f[j]=1;
		}
		t=1-t;
	}
	return 1;
}	
int main()
{
	int i,j,s;
	scanf("%d%d",&n,&k);
	i=1;
	j=n;
	while (i+1<j)
	{
		s=(i+j)/2;
		if (find(s))
			i=s;
		else j=s-1;
		memset(f,0,n+1);
	}
	while (find(i))
	{
		memset(f,0,n+1);
		i++;
	}
	printf("%d\n",i-1);
	return 0;
}
