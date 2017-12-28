#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long LL;
int a[110][110];
LL d[110][210];
char e[1100];
int main(void)
{
	int i,j,n,m,top,lo;
	LL p,q,sump;
	scanf("%d%d",&n,&m);
	while(getchar()==' '){;}
	for(i=1;i<=n;i++)
	{
		gets(e);
		lo=strlen(e);
		top=0;
		for(j=0;j<lo;j++)
		{
			if(e[j]=='*')
			{
				top++;
				a[i][top]=1;
			}
			else if(e[j]=='.')
			{
				top++;
				a[i][top]=0;
			}
		}
	}
	if(a[1][1]==1)
	{
		d[1][1]=d[1][3]=1;
		d[1][2]=0;
	}
	else
	{
		d[1][1]=d[1][3]=0;
		d[1][2]=2;
	}
	for(i=2;i<=n;i++)
	{
		d[i][1]=(a[i][1]==1)?d[i-1][1]:0;
		d[i][2*i+1]=(a[i][i]==1)?d[i-1][2*i-1]:0;
		for(j=2;j<2*i+1;j++)
		{
			if(j%2==1)
			{
				sump=d[i-1][j-1]*2;
				sump=sump+((a[i][j/2]==1)?d[i-1][j-2]:0);
				sump=sump+((a[i][j/2+1]==1)?d[i-1][j]:0);
			}
			else
			{
				sump=(a[i][j/2]==1)?0:2*d[i-1][j-1];
			}
			d[i][j]=sump;
		}
	}
	if(q==0)
	{
		printf("0/1\n");
	}
	else
	{
		p=d[n][2*m+1];
		q=(LL)1<<n;
		while((p%2==0)&&(q%2==0))
		{
			p=p/2;
			q=q/2;
		}
		printf("%lld/%lld\n",p,q);
	}
	return 0;
}
