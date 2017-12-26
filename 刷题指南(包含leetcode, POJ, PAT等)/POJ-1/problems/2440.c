#include<stdio.h>
int main()
{
	int n,i,a[200]={1,2,4,6};
	for(i=4;i<200;++i)
		a[i]=(a[i-1]+a[i-3]+a[i-4])%2005;
	while(scanf("%d",&n)!=EOF)
		printf("%d\n",a[n%200]);
	return 0;
}
