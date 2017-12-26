#include<stdio.h>
int weight[50000],strength[50000],d[50000];
void quick(int s,int t);
void swap(int i,int j);
int main()
{
	int n,i,j,sum,max;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&weight[i],&strength[i]);
		d[i]=weight[i]+strength[i];
	}
	quick(0,n-1);
	max=-strength[0];
	sum=weight[0];
	for (i=1;i<n;i++)
	{
		j=sum-strength[i];
		if (j>max)
			max=j;
		sum+=weight[i];
	}
	printf("%d\n",max);
	return 0;
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
			}while(!(d[s]<=d[i] || i==t));
			do{
				j--;
			}while(!(d[s]>=d[j] || j==s));
			if (i<j)
				swap(i,j);
			else break;
		}
		swap(s,j);
		quick(s,j-1);
		quick(j+1,t);
	}
}
void swap(int i,int j)
{
	int t;
	t=d[i];
	d[i]=d[j];
	d[j]=t;
	t=weight[i];
	weight[i]=weight[j];
	weight[j]=t;
	t=strength[i];
	strength[i]=strength[j];
	strength[j]=t;
}
