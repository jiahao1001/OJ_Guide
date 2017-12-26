#include <stdio.h>
int main()
{
	int n,i;
	char st[10000];
	scanf("%s",st);
	while (st[0]!='0')
	{
		n=0;
		i=0;
		while (st[i]!='\0')
			n+=st[i++]-'0';
		n%=9;
		if (n==0)
			n=9;
		printf("%d\n",n);
		scanf("%s",st);
	}
	return 0;
}
