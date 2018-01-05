#include<stdio.h>
int main()
{
	int h; // ‰»Î
	int i,j;
	while(scanf("%d",&h)!=EOF)
	{
		int maxLine = h+2*(h-1);
		for(i=1;i<=h;i++)
		{
			for(j=1;j<=maxLine;j++)
				if(j<maxLine-(h+2*(i-1))+1)
					printf(" ");
				else
					printf("*");
			printf("\n");
		} 
	}
	return 0;
}