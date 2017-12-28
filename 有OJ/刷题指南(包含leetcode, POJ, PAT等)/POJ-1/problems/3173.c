#include <stdio.h>
int make(int p)
{
	if (p%9==0)
		return 9;
	else return p%9;
}
int main()
{
	int i,j,n,s,f;
	scanf("%d%d",&n,&s);
	for (i=0;i<n;i++)
	{
		for (j=0;j<i;j++)
			printf("  ");
		printf("%d",s);
		f=make(s+i+1);
		s=make(f+1);
		for (j=1;j<n-i;j++)
		{
			printf(" %d",f);
			f=make(f+j+i+1);
		}
		putchar('\n');
	}
	return 0;
}
