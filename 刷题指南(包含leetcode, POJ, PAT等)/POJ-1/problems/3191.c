#include <stdio.h>
int i;
char str[50]={'\0'};
int mod (int p)
{
	if (p<0 && p%(-2)==-1)
	{
		str[i++]='1';
		return (p-1)/(-2);
	}
	if (p%(-2)==0)
		str[i++]='0';
	else str[i++]='1';
	return p/(-2);
}
int main()
{
	int n;
	i=0;
	scanf("%d",&n);
	do
	{
		n=mod(n);
	}while (n!=0);
	while (i>=0)
		putchar(str[--i]);
	putchar('\n');
	return 0;
}
