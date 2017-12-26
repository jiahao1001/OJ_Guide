#include<stdio.h>
int M,T,U,F,D;
int main()
{
	int i,j;
	int sum=0;
	char c;
	scanf("%d%d%d%d%d\n",&M,&T,&U,&F,&D);
	for (i=0;i<T;i++)
	{
		scanf("%c\n",&c);
		if (sum>=M)
			continue;
		j=i;
		if (c=='u' || c=='d')
			sum+=U+D;
		else if (c=='f')
			sum+=F+F;
	}
	printf("%d\n",j);
	return 0;
}
