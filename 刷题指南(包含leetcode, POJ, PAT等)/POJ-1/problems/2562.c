#include<stdio.h>
int main()
{
	int c,s;
	unsigned m,n;
	scanf("%u%u",&m,&n);
	while (n!=0 || m!=0)
	{
		c=0;
		s=0;
		while (n!=0 || m!=0)
		{
			s+=n%10+m%10;
			if (s>9)
				c++;
			n/=10;
			m/=10;
			s/=10;
		}
		if(c==0)
			printf("No carry operation.\n");
        else if (c>1)
			printf("%d carry operations.\n",c);
        else printf("1 carry operation.\n");
		scanf("%u%u",&m,&n);
	}
	return 0;
}
