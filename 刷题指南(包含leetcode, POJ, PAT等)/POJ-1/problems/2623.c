#include<stdio.h>
int median[125001],N;
void ADJUST(int i,int n)
{
	int j=i<<1,temp=median[i];
	while (j<=n)
	{
		if (j<n && median[j]<median[j+1])
			j++;
		if (temp>=median[j])
			break;
		median[j>>1]=median[j];
		j=j<<1;
	}
	median[j>>1]=temp;
}
int main()
{
	int i,j,n;
	double mid;
	scanf("%d",&N);
	if (N%2==0)
		n=N/2+1;
	else n=(N+1)/2;
	for (i=1;i<=n;i++)
		scanf("%d",&median[i]);
	for (i=n/2;i>0;i--)
		ADJUST(i,n);
	for (i=N-n;i>0;i--)
	{
		scanf("%d",&j);
		if (j<median[1])
		{
			median[1]=j;
			ADJUST(1,n);
		}
	}
	mid=(double)median[1];
	if (N%2==0)
	{
		if (median[2]>median[3])
			mid=(mid+median[2])/2;
		else mid=(mid+median[3])/2;
	}
	printf("%.1lf\n",mid);
	return 0;
}
