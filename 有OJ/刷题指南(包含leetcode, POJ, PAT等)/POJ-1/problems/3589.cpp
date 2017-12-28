#include<stdio.h>
int n;
char s[10],t[10];
int main()
{
	int i,j;
	int a,b;
	int num[10];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		a=0;
		b=0;
		scanf("%s%s",s,t);
		for (j=0;j<10;j++)
			num[j]=0;
		for (j=0;j<4;j++)
			num[s[j]-'0']=1;
		for (j=0;j<4;j++)
		{
			if (num[t[j]-'0']==1)
				b++;
			if (s[j]==t[j])
			{
				a++;
				b--;
			}
		}
		printf("%dA%dB\n",a,b);
	}
	return 0;
}
