#include "stdio.h"

int w(char c)
{
	if(c<='9')
		return c-'0';
	if(c<='Z')
		return c-'A'+10;
	return c-'a'+36;
}

int main() {
	int i,t,sum,max;
	char c;
	while((c=getchar())>0)
	{
		sum=w(c);
		t=sum;max=t;
		//printf("%d\n",sum);
		while((c=getchar())!='\n')
		{
			t=w(c);
			if(t>max)
				max=t;
			sum+=t;
		}
		for(i=max;i<62;i++)
		{
			if(sum%i==0)
			{
				printf("%d\n",i+1);
				break;
			}
		}
		if(i==62)
			printf("such number is impossible!\n");
	}
	return 0;
}
