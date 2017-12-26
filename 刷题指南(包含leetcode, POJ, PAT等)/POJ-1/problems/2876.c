#include<stdio.h>
int base[13]={0,1,3,9,27,81,243,729,2187,6561,19683,59049,177147};
void print(int p)
{
	int i;
	if (p==0)
		putchar('-');
	else {
		print(p-1);
		for (i=base[p];i>0;i--)
			putchar(' ');
		print(p-1);
	}
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		print(n);
		putchar('\n');
	}
	return 0;
}
