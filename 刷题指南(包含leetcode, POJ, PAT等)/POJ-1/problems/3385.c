#include <stdio.h>
int A,a,B,b,P;
int main ()
{
	scanf("%d%d%d%d%d",&A,&a,&B,&b,&P);
	if (A<=P && B<=P && (A+B<=P || A<=b || B<=a))
		printf("Yes\n");
	else printf("No\n");
	return 0;
}
