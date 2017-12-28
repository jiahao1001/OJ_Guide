#include <stdio.h>
#include <string.h>
int muil(int n,int p)
{
	int i,j,a,b;
	char s[800]={'1'};
	for (i=2;i<=n;i++)
	{
		for (j=strlen(s)-1;j>=0;j--)
		{
			a=(s[j]-'0')*i;
			b=j;
			s[b++]=a%10+'0';
			a/=10;
			while (a)
			{
				if (s[b]=='\0')
					s[b]=a%10+'0';
				else s[b]+=a%10;
				a/=10;
				if (s[b]>'9')
				{
					s[b]-=10;
					a++;
				}
				b++;
			}
		}
	}
	n=strlen(s);
	for (i=0,j=0;i<n;i++)
		if (s[i]-'0'==p)
			j++;
	return j;
}
int main ()
{
	int n,p,t,i;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d%d",&n,&p);
		printf("%d\n",muil(n,p));
	}
	return 0;
}
