#include<stdio.h>
int n,d,k;
bool cow[1000][15]={false};
void zuhe(int c[],int r,int n);
bool equal(int i,int c[],int r);
int cozuhe(int m,int k);
int main()
{
	int i,j,b,c,max=0,s;
	int base[15];
	scanf("%d%d%d",&n,&d,&k);
	k=d-k;
	for (i=0;i<k;i++)
		base[i]=i;
	for (i=0;i<n;i++)
	{
		scanf("%d",&c);
		for (j=0;j<c;j++)
		{
			scanf("%d",&b);
			cow[i][b-1]=true;
		}
	}
	for (i=cozuhe(d,k);i>0;i--)
	{
		s=0;
		for (j=0;j<n;j++)
		{
			for (c=0;c<k;c++)
				if (cow[j][base[c]]==true)
					break;
			if (c==k)
				s++;
		}
		if (s>max)
			max=s;
		zuhe(base,k,d);
	}
	printf("%d\n",max);
	return 0;
}
void zuhe(int c[],int r,int n)
{
	int i=0,j=0;
	for (;i<r;i++)
	{
		if (c[i]<n-1 && equal(i,c,r)==true)
			j=i;
	}
	c[j]++;
	for (i=j+1;i<r;i++)
		c[i]=c[j]+i-j;
}
bool equal(int i,int c[],int r)
{
	int j;
	for (j=0;j<r;j++)
	{
		if (c[i]+1==c[j])
			return false;
	}
	return true;
}
int cozuhe(int m,int k) //ÆÕÍ¨¾«¶È
{
	int i;
	int s=1;
	if (k>m-k)
		k=m-k;
	for (i=1;i<=k;i++)
		s=s*(m+1-i)/i;
	return s;
}
