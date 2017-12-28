#include <stdio.h>
int main()
{
	int m,i,s;
	unsigned n,j;
	scanf("%d",&m);
	for (i=1;i<=m;i++)
	{
		s=0;
		scanf("%d%d",&j,&n);
		for (j=2;j*j+j<=2*n;j+=2)
			if (n%j!=0 && n%(j/2)==0)
				s++;
		for (j=3;j*j+j<=2*n;j+=2)
			if (n%j==0)
				s++;
		printf("%d %d\n",i,s);
	}
	return 0;
}
