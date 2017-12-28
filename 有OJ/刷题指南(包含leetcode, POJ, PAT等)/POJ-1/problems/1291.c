#include<stdio.h>
int Parent[1001],sen[1001],tru[1001];
int root(int i);
void  merge(int i,int j);
int main()
{
	int i,j,k,n,p,x,y,a,b;
	char s[20],t[10],r[10];
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=1;i<=n;i++)
		{
			Parent[i]=-1;
			sen[i]=-1;
			tru[i]=1;
		}
		for (i=1;i<=n;i++)
		{
			scanf("%s%d%s%s",s,&p,t,r);
			j=root(i);
			p=root(p);
			if (r[0]=='t')
			{
				merge(j,p);
				if (sen[j]==-1 && sen[p]!=-1)
					sen[j]=sen[p];
				else if (sen[j]!=-1 && sen[p]==-1)
					sen[p]=sen[j];
				else if (sen[j]!=-1 && sen[p]!=-1)
				{
					merge(sen[j],sen[p]);
					sen[j]=root(sen[j]);
					sen[p]=sen[j];
				}
			}
			else {
				if (sen[j]!=-1)
					merge(p,sen[j]);
				sen[j]=root(p);
				if (sen[p]!=-1)
					merge(j,sen[p]);
				sen[p]=root(j);
			}
		}
		for (i=1;i<=n;i++)
		{
			if (sen[i]>-1)
			{
				x=root(i);
				y=root(sen[i]);
				if (x==y)
					break;
				for (j=1,a=0,b=0;j<=n;j++)
				{
					k=root(j);
					if (k==x)
					{
						a++;
						sen[j]=-1;
					}
					else if (k==y)
					{
						b++;
						sen[j]=-1;
					}
				}
				if (a>b)
					x=y;
				for (j=1;j<=n;j++)
					if (root(j)==x)
						tru[j]=0;
			}
		}
		if (i<=n)
			printf("Inconsistent\n");
		else{
			for (i=1,a=0;i<=n;i++)
				if (tru[i]==1)
					a++;
			printf("%d\n",a);
		}
		scanf("%d",&n);
	}
	return 0;
}
int root(int i)
{
	int r,p;
	for (r=i;Parent[r]>0;r=Parent[r]);
	while (i!=r)
	{
		p=i;
		i=Parent[i];
		Parent[p]=r;
	}	
	return r;
}
void  merge(int i,int j)
{
	i=root(i);
	j=root(j);
	if (i==j)
		return ;
	if (Parent[i]<Parent[j])
	{
		Parent[i]+=Parent[j];
		Parent[j]=i;
	}
	else 
	{
		Parent[j]+=Parent[i];
		Parent[i]=j;
	}
}
