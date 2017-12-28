#include<stdio.h>
int n;
int A[256],B[256];
void cal(int s,int d,int p)
{
	int a=A[s]+A[d];
	int b=A[s]-A[d];
	B[p]=a/2;
	B[p+1]=b/2;
}
int main()
{
	int i,j;
	int step;
	while (scanf("%d",&n),n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%d",&A[i]);
		B[0]=A[0];
		step=1;
		while (step<n)
		{
			for (i=0,j=0;i<step;i++,j+=2)
				cal(i,i+step,j);
			step+=step;
			for (i=0;i<step;i++)
				A[i]=B[i];
		}
		for (i=0;i<n;i++)
			printf("%d ",B[i]);
		putchar('\n');
	}
	return 0;
}
