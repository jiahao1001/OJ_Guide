#include<stdio.h>
void merge(int s,int u,int v);
void mergesort(int first,int last);
int x[500000],z[500000];
__int64 reverse;//ÄæĞòÊı
int main()
{
	int n,i;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%d",&x[i]);
		reverse=0;
		mergesort(0,n-1);
		printf("%I64d\n",reverse);
		scanf("%d",&n);
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
