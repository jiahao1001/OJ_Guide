#include <stdio.h>
#define MAX 50005
int main ()
{
	long stack[MAX]={0};
	long n,w,i;
	long t=0,count=0;
	long a,b;
	scanf("%ld%ld", &n, &w);
	for (i=0;i<n;i++)
	{
		scanf("%ld%ld",&a,&b);
		while (b<stack[t])
		{
			t--;
			count++;
		}
		if (b>stack[t]) 
			stack[++t]=b;
	}
	b=0;
    while (b<stack[t] && t!=-1)
	{
		t--;
		count++;
	}
	printf("%ld\n",count);
	return 0;
}
