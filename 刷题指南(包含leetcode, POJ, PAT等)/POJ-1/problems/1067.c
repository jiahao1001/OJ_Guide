#include <stdio.h>
#define R 1.61803398874989484820458683436564
#define r 0.61803398874989484820458683436564
int main()
{
	int m,n,temp;
	int num;
	while((scanf("%d %d",&m,&n))!=EOF)
	{
		if (m>n)
		{
			temp=m;
			m=n;
			n=temp;
		}
		num=(int)m*r;
		if (m!=(int)(num*R))
			num++;
		if (n==(int)(num*R)+num)
			printf("0\n");
		else printf("1\n");
	}
	return 0;
}
