#include<stdio.h>
int pow(int A,int N)
{
	int s=A,i;
	for (i=1;i<N;i++)
		s*=A;
	return s;
}
int main()
{
	int i,j,k;
	int B,N;
	scanf("%d%d",&B,&N);
	while (B!=0 || N!=0)
	{
		for (i=1,k=1;(j=pow(i,N))<B;i++)
			k=j;
		if (j-B>B-k)
			i--;
		printf("%d\n",i);
		scanf("%d%d",&B,&N);
	}
	return 0;
}
