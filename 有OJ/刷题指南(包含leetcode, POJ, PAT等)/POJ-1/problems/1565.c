#include <stdio.h>
int main()
{
	int i,j,m,n;
	char st[32];
	scanf("%s",st);
	while (st[0]!='0')
	{
		i=0;
		while (st[i]!='\0')
			i++;
		m=0;
		n=1;
		for (j=i-1;j>-1;j--)
		{
			n*=2;
			m+=(st[j]-'0')*(n-1);
		}
		printf("%d\n",m);
		scanf("%s",st);
	}
	return 0;
}
