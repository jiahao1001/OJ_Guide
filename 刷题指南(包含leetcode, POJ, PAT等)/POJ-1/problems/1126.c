#include<stdio.h>
char str[300];
int sentence(int p)
{
	int q;
	if (str[p]>='p' && str[p]<='z')
		return p+1;
	if (str[p]=='N')
		return sentence(p+1);
	if (str[p]=='C' || str[p]=='D' || str[p]=='E' || str[p]=='I')
	{
		q=sentence(p+1);
		if (q>=0)
			return sentence(q);
		else return -1;
	}
	return -1;
}
int main()
{
	int p;
	while (scanf("%s",str)!=EOF)
	{
		p=sentence(0);
		if (p>0 && str[p]=='\0')
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
