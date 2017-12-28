#include<stdio.h>
int main()
{
	int i,j,n,p,q;
	char s[6];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		p=0;
		q=0;
		scanf("%s",s);
		for (j=0;s[j]!=':';j++)
			p=p*10+s[j]-'0';
		for (j++;s[j]!='\0';j++)
			q=q*10+s[j]-'0';
		if (q==0)
		{
			p+=12;
			printf("%d\n",p%24==0 ? 24 : p%24);
		}
		else printf("0\n");
	}
	return 0;
}
