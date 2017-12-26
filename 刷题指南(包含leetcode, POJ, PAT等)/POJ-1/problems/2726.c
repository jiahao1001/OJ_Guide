#include<stdio.h>
int d[10000],c[10000];
void quick(int s,int t);
void swap(int i,int j);
int main()
{
	int n,i,j,s,y;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%d%d",&d[i],&c[i]);
		quick(0,n-1);
		s=0;
		y=10001;
		for (i=0;i<n;i++)
		{
			for (j=i+1;j<n && d[i]==d[j];j++)
			{
				if (c[j]<c[i])
					c[i]=c[j];
			}
			if (c[i]<y)
			{
				y=c[i];
				s++;
			}
		}
		printf("%d\n",s);
		scanf("%d",&n);
	}
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
	t=c[i];
	c[i]=c[j];
	c[j]=t;
}
