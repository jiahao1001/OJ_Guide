#include<stdio.h>
#define MAXNUM 1000000
short east[MAXNUM],west[MAXNUM],tmparray[MAXNUM];
__int64 reverse;
void merge(int s,int u,int v)
{
	int i=s,j=u+1,q=0;
	while (i<=u && j<=v)
	{
		if (west[i]<=west[j])
			tmparray[q++]=west[i++];
		else {
			tmparray[q++]=west[j++];
			reverse+=u-i+1;
		}
	}
	while (i<=u)
		tmparray[q++]=west[i++];
	while (j<=v)
		tmparray[q++]=west[j++];
	for(i=0;i<q;i++)
		west[s+i]=tmparray[i];
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
void swap(int i,int j)
{
	short temp;
	temp=east[i];
	east[i]=east[j];
	east[j]=temp;
	temp=west[i];
	west[i]=west[j];
	west[j]=temp;
}
void quick(int s,int t)
{
	int i,j;
	if (s<t)
	{
		i=s;
		j=t+1;
		while (1)
		{
			do{
				i++;
			}while(!(east[s]<=east[i] || i==t));
			do{
				j--;
			}while(!(east[s]>=east[j] || j==s));
			if (i<j)
				swap(i,j);
			else break;
		}
		swap(s,j);
		quick(s,j-1);
		quick(j+1,t);
	}
}
int main()
{
	int i,j,k,l,t,n,m;
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		scanf("%d%d%d",&n,&m,&k);
		for (j=0;j<k;j++)
			scanf("%d%d",&east[j],&west[j]);
		quick(0,k-1);
		reverse=0;
		for (j=0;j<k;j++)
		{
			for (l=j+1;l<k && east[j]==east[l];l++)
			{
				if (west[j]>west[l])
					reverse--;
			}
		}
		mergesort(0,k-1);
		printf("Test case %d: %I64d\n",i,reverse);
	}
	return 0;
}
