#include<stdio.h>
int main()
{
 	float s;
 	int w,m,c;
 	while(1)
 	{
		c=0;
 	 	scanf("%f%d%d",&s,&w,&m);
 	 	if (s==0)
			break;
		if (s<=4.5 && w>=150 && m>=200)
		{
			c=1;
			printf("Wide Receiver");
		}
		if (s<=6.0 && w>=300 && m>=500)
		{
			if (c==1)
				printf(" ");
			c=1;
			printf("Lineman");
		}
 	 	if (s<=5.0 && w>=200 && m>=300)
		{
			if (c==1)
				printf(" ");
			c=1;
			printf("Quarterback");
		}
 	 	if (c==0)
 	 	printf("No positions");
 	 	printf("\n");
 	}
 	return 0;
}
