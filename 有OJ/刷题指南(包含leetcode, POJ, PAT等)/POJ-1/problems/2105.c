#include <stdio.h>
int main()
{
	int n,i,j,k,c[4];
	char s[50];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%s",s);
		for (j=0;j<4;j++)
		{
			c[j]=0;
			for (k=0;k<8;k++)
				c[j]=c[j]*2+s[j*8+k]-'0';
		}
		printf("%d.%d.%d.%d\n",c[0],c[1],c[2],c[3]);
	}
	return 0;
}
