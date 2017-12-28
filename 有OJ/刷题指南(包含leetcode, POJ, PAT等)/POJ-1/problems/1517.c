#include <stdio.h>
int main()
{
	int n;
	double e=1,p=1;
	printf("n e\n- -----------\n0 %.9lf\n",e);
	for (n=1;n<10;n++)
	{
		p=p/n;
		e+=p;
		printf("%d %.9lf\n",n,e);
	}
	return 0;
}
