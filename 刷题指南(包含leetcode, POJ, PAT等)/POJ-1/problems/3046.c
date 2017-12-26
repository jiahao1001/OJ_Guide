#include<stdio.h>
#include<string.h>
int family[1001]={0};
int coefficient[100001]={0};
int temp[100001];
int T,A,S,B,Q;
void multiply(int p)
{
	int i,j,k;
	for (i=0;i<=Q;i++)
		temp[i]=coefficient[i];
	for (i=1;i<=family[p];i++)
	{
		for (j=0;j<=Q;j++)
			temp[j+i]+=coefficient[j];
	}
	if (Q<B)
		Q+=family[p];
	else Q=B;
	for (i=0;i<=Q;i++)
		coefficient[i]=temp[i]%1000000;
}
int main()
{
	int i,j;
	scanf("%d%d%d%d",&T,&A,&S,&B);
	for (i=0;i<A;i++)
	{
		scanf("%d",&j);
		family[j]++;
	}
	Q=family[1];
	for (i=0;i<=Q;i++)
		coefficient[i]=1;
	for (i=2;i<=T;i++)
		multiply(i);
	for (i=S,j=0;i<=B;i++)
	{
		j+=coefficient[i];
		j%=1000000;
	}
	printf("%d\n",j);
	return 0;
}
