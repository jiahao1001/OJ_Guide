#include <stdio.h>
int main()
{
	int a,i;
	for (i=0;i<3;i++)
	{
		scanf("%d",&a);
		if (a<=168)
		{
			printf("CRASH %d\n",a);
			return 0;
		}
	}
	printf("NO CRASH\n");
	return 0;
}
