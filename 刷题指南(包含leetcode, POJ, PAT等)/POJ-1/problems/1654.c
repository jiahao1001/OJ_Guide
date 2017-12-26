#include<stdio.h>
int main()
{
	int n,i,x1,y1,x2,y2;
	__int64 s;
	int num[10][2]={0,0,-1,-1,0,-1,1,-1,-1,0,0,0,1,0,-1,1,0,1,1,1};
	char c;
	scanf("%d\n",&n);
	for (i=0;i<n;i++)
	{
		s=0;
		x1=0;
		y1=0;
		while ((c=getchar())!='5')
		{
			x2=x1+num[c-'0'][0];
			y2=y1+num[c-'0'][1];
			s+=(y1+y2)*(x2-x1);
			x1=x2;
			y1=y2;
		}
		getchar();
		if (s<0)
			s=-s;
		printf("%I64d",s/2);
		if (s%2==1)
			printf(".5");
		printf("\n");
	}
	return 0;
}
