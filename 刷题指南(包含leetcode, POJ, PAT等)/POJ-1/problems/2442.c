#include<stdio.h>
#include<stdlib.h>
int num,K[30000],key[30001];
short queue[102][2000],rear[30001][102];
void ADJUST(int i,int n);
void HEAP(int m,int n);
int cmp(const void *a, const void *b);
int main()
{
	int n,m,test,t,i,j;
	scanf("%d",&test);
	for (t=0;t<test;t++)
	{
		scanf("%d%d",&m,&n);
		for (i=1,K[1]=0;i<=m;i++)
		{
			for (j=0;j<n;j++)
				scanf("%d",&queue[i][j]);
			qsort(queue[i],n,sizeof(queue[i][0]),cmp);
			K[1]+=queue[i][0];
			rear[0][i]=0;
		}
		num=1;
		key[0]=K[1];
		rear[0][0]=1;
		HEAP(m,n);
	}
	return 0;
}
void ADJUST(int i,int n)
{
	int j;
	short temp=K[i];
	j=i<<1;
	while (j<=n)
	{
		if (j<n && K[j]>K[j+1])
			j++;
		if (temp<=K[j])
			break;
		K[j>>1]=K[j];
		j=j<<1;
	}
	K[j>>1]=temp;
}
void HEAP(int m,int n)
{
	int i,j,k,l,h;
	printf("%d ",K[1]);
	for (i=n;i>1;i--)
	{
		for (j=0;j<num;j++)
			if (K[1]==key[j])
				break;
		k=rear[j][0];
		for (h=k+1;h<=m;h++)
		{
			rear[num][0]=h;
			for (l=1;l<=m;l++)
				rear[num][l]=rear[j][l];
			key[num]=key[j]+queue[h][++rear[num][h]]-queue[h][rear[num][h]-1];
			num++;
			K[num]=key[num-1];
		}
		key[j]=key[j]+queue[k][++rear[j][k]]-queue[k][rear[j][k]-1];
		K[1]=key[j];
		for	(j=num/2;j>=1;j--)
			ADJUST(j,num);
		printf("%d ",K[1]);
	}
	printf("\n");
}
int cmp(const void *a, const void *b)
{
	short x,y;
	x=*(short *)a;
	y=*(short *)b;
	if (x<y)
		return -1;
	else if (x>y)
		return 1;
	else return 0;
}
