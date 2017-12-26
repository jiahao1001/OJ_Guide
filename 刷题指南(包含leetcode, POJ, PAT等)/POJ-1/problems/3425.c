#include<stdio.h>
int N;
int question[1000001]={0};
int sum=0;
int main()
{
	int i;
	int a,b,c;
	scanf("%d\n",&N);
	for (i=0;i<N;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if (b==0)
			sum+=10;
		else
		{
			sum+=question[a]*10;
			question[a]++;
			if (c==1)
				sum+=40;
			else sum+=20;
		}
	}
	printf("%d\n",sum);
	return 0;
}
