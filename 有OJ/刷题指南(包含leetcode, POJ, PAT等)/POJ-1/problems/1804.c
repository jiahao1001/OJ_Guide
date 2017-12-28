#include<stdio.h>
void merge(int s,int u,int v);
void mergesort(int first,int last);
int x[1000],z[1000];
int reverse;
int main()
{
	int n,m,i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for (j=0;j<m;j++)
			scanf("%d",&x[j]);
		reverse=0;
		mergesort(0,m-1);
		printf("Scenario #%d:\n%d\n\n",i,reverse);
	}
	return 0;
}
void merge(int s,int u,int v)
{
	int i=s,j=u+1,q=0;
	while (i<=u && j<=v)
	{
		if (x[i]<=x[j])
			z[q++]=x[i++];
		else {
			z[q++]=x[j++];
			reverse+=u-i+1;
		}
	}
	while (i<=u)
		z[q++]=x[i++];
	while (j<=v)
		z[q++]=x[j++];
	for(i=0;i<q;i++)
		x[s+i]=z[i];
}
void mergesort(int first,int last)
{
	int mid;
	if (first<last)
	{
		mid=(first+last)/2;
		mergesort(first,mid);
		mergesort(mid+1,last);
		merge(first,mid,last);
	}
}
