#include<stdio.h>
int main()
{
	int h; // ‰»Î
	int i,j;
	while(scanf("%d",&h)!=EOF)
	{
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=2*(h-i);j++)
				printf(" ");
			for(j=1;j<=h+2*(i-1);j++)
				printf("*");
			printf("\n");
		}
	}
	return 0;
}