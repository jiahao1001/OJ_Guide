#include<stdio.h>
int s[50001];
int root(int i);
void  merge(int i,int j);
int main()
{
	int n,m,c,i,j=0,a,b;
	scanf("%d%d",&n,&m);
	while (n!=0 || m!=0)
	{
		j++;
		for (i=n;i>0;i--)
			s[i]=-1;
		for (i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		for (i=1,c=0;i<=n;i++)
			if (s[i]<0)
				c++;
		printf("Case %d: %d\n",j,c);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
int root(int i)
{
	int r,p;
	for (r=i;s[r]>0;r=s[r]);
	while (i!=r)
	{
		p=i;
		i=s[i];
		s[p]=r;
	}	
	return r;
}
void  merge(int i,int j)
{
	i=root(i);
	j=root(j);
	if (i==j)
		return ;
	if (s[i]<s[j])
	{
		s[i]+=s[j];
		s[j]=i;
	}
	else 
	{
		s[j]+=s[i];
		s[i]=j;
	}
}
