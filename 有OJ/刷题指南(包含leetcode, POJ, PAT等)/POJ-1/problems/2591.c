#include<stdio.h>
unsigned p[10000000]={1};
int main()
{
	int i=0,j=0,c=1;
	while (c<10000000)
	{
		if (p[i]*2<p[j]*3)
		{
			if (p[i]*2+1==p[c-1])
				i++;
			else p[c++]=p[i++]*2+1;
		}
		else {
			if (p[j]*3+1==p[c-1])
				j++;
			else p[c++]=p[j++]*3+1;
		}
	}
	while (scanf("%d",&c)!=EOF)
		printf("%d\n",p[c-1]);
	return 0;
}
