#include<stdio.h>
int N,cow;
int Group[30001]={0};
int main()
{
	int i,j,k;
	int min;
	scanf("%d",&N);
	for (i=1,j=0;i<=N;i++)
	{
		scanf("%d",&cow);
		Group[i]=Group[i-1];
		if (cow==2)
			Group[i]++;
	}
	j=N-Group[N];
	min=N;
	for (i=0;i<=N;i++)
	{
		k=Group[i]+j-(i-Group[i]);
		if (k<min)
			min=k;
	}
	printf("%d\n",min);
	return 0;
}
