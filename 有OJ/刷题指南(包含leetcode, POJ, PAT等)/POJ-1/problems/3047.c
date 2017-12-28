#include<stdio.h>
int main()
{
	int y,m,d,a[12]={31,28,31,30,31,30,31,31,30,31,30,31},i,j,sum;
	scanf("%d%d%d",&y,&m,&d);
	sum=y*365-365;
	sum+=(y-1)/4-(y-1)/100+(y-1)/400;
	for(j=0;j<m-1;j++)
		sum+=a[j];
	if (m>2 && ((y%4==0 && y%100!=0) || y%400==0))
		sum++;
	sum+=d-1;
	sum%=7;
	switch(sum)
	{
		case 0:printf("monday\n");break;
		case 1:printf("tuesday\n");break;
		case 2:printf("wednesday\n");break;
		case 3:printf("thursday\n");break;
		case 4:printf("friday\n");break;
		case 5:printf("saturday\n");break;
		case 6:printf("sunday\n");break;
	}
	return 0;
}
