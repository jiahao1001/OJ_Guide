#include<stdio.h>
int Yang(int n,int p)
{
	int a=n/p;
	int b=n%p;
	if (n==0)
		return 1;
	return (b+1)*Yang(a,p);
}
int main()
{
	int n,p,sum,t=1;
	char digit[5];
	scanf("%d%d",&p,&n);
	while (p!=0 || n!=0)
	{
		sum=Yang(n,p);
		sum%=10000;
		digit[0]='0'+sum/1000;
		sum%=1000;
		digit[1]='0'+sum/100;
		sum%=100;
		digit[2]='0'+sum/10;
		sum%=10;
		digit[3]='0'+sum;
		digit[4]='\0';
		printf("Case %d: %s\n",t++,digit);
		scanf("%d%d",&p,&n);
	}
	return 0;
}
