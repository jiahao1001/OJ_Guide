#include<stdio.h>
int d[9][10]={0},e[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
void count(int n,int a[]);
void cal(int n);
int main()
{
	int n,m,i,a[10],b[10];
	for (i=1;i<10;i++)
		cal(i);
	scanf("%d%d",&n,&m);
	while (n!=0 || m!=0)
	{
		if (m<n)
		{
			i=n;
			n=m;
			m=i;
		}
		count(n-1,a);
		count(m,b);
		for (i=0;i<9;i++)
			printf("%d ",b[i]-a[i]);
		printf("%d\n",b[9]-a[9]);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
void count(int n,int a[])
{
	int i,j,m,p,c=1;
	if (n==0)
	{
		a[0]=1;
		for (i=1;i<10;i++)
			a[i]=0;
		return ;
	}
	for (i=0;n>=e[i];i++);
	i--;
	for (j=0;j<10;j++)
		a[j]=d[i][j];
	while (i>0)
	{
		m=n/e[i];
		p=m-c;
		for (j=c;j<m;j++)
			a[j]+=e[i];
		for (j=0;j<10;j++)
			a[j]+=i*p*e[i-1];
		n%=e[i];
		a[m]+=n+1;
		i--;
		c=0;
	}
	for (j=0;j<=n;j++)
		a[j]++;
}
void cal(int n)
{
	int i;
	if (n==1)
	{
		for (i=0;i<10;i++)
			d[1][i]=1;
	}
	else{
		for (i=0;i<10;i++)
			d[n][i]+=d[n-1][i];
		d[n][0]+=(n-1)*(e[n-1]-e[n-2]);
		for (i=1;i<10;i++)
			d[n][i]+=e[n-1]+(n-1)*(e[n-1]-e[n-2]);
	}
}
