#include<stdio.h>
#include<stdlib.h>
int n;
int A[500][500],B[500][500],C[500][500];
__int64 a[500],b[500],c[500],X[500];
void input(int x[][500])
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			scanf("%d",&x[i][j]);
}
void muti(int x[][500],__int64 *y,__int64 *z)//x(n*n)y(n*1)=z(n*1)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		z[i]=0;
		for (j=0;j<n;j++)
			z[i]+=y[j]*x[i][j];
	}
}
int main()
{
	int j;
	scanf("%d",&n);
	srand(n);
	input(A);
	input(B);
	input(C);
	for (j=0;j<n;j++)
		X[j]=rand();
	muti(C,X,c);
	muti(B,X,b);
	muti(A,b,a);
	for (j=0;j<n;j++)
		if (c[j]!=a[j])
			break;
	if (j<n)
		printf("NO\n");
	else printf("YES\n");
	return 0;
}
