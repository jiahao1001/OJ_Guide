#include<stdio.h>
int Factorial[10]={1,1,2,6,24,120,720,5040,40320,362880};
int main()
{
	int n,i;
    scanf("%d",&n);
	while (n>=0)
	{
		i=9;
		while (n>0)
		{
			while (i>=0 && n<Factorial[i])
				i--;
			if (i<0)
				break;
			n-=Factorial[i--];
		}
		if (n==0 && i!=9)
			printf("YES\n");
		else printf("NO\n");
		scanf("%d",&n);
	}
	return 0;
}
