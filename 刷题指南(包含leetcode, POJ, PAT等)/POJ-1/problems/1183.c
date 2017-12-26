#include<stdio.h>
int main()
{
	unsigned long a,i;
	scanf("%ld",&a);
	for(i=a;;i--)
		if ((a*a+1)%i==0)
			break;
	printf("%ld\n",2*a+(a*a+1)/i+i);
	return 0;
}
