#include <stdio.h>
int main()
{
	int n,i,s=1;
	scanf("%d",&n);
	for (i=2;i*i+i<=2*n;i+=2)
		if (n%i!=0 && n%(i/2)==0)
			s++;
	for (i=3;i*i+i<=2*n;i+=2)
		if (n%i==0)
			s++;
	printf("%d\n",s);
	return 0;
}
