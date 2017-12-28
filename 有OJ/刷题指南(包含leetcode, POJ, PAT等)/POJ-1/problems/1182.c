#include<stdio.h>
int Parent[50001],eat[50001],beeat[50001];
int root(int i);
int  merge(int i,int j);
int main()
{
	int i,k,n,x,y,d,fake=0;
	scanf("%d%d",&n,&k);
	for (i=0;i<=n;i++)
	{
		Parent[i]=-1;
		eat[i]=-1;
		beeat[i]=-1;
	}
	for (i=0;i<k;i++)
	{
		scanf("%d%d%d",&d,&x,&y);
		if (x>n || y>n || (d==2 && x==y))
		{
			fake++;
			continue;
		}
		x=root(x);
		y=root(y);
		if (eat[x]!=-1)
			eat[x]=root(eat[x]);
		if (beeat[x]!=-1)
			beeat[x]=root(beeat[x]);
		if (eat[y]!=-1)
			eat[y]=root(eat[y]);
		if (beeat[y]!=-1)
			beeat[y]=root(beeat[y]);
		if (d==1)
		{
			if (eat[x]==y || eat[y]==x )
				fake++;
			else merge(x,y);
		}
		else{
			if (x==y || eat[y]==x)
				fake++;
			else {
				if (eat[x]==-1)
					eat[x]=y;
				else merge(y,eat[x]);
				if (beeat[y]==-1)
					beeat[y]=x;
				else merge(x,beeat[y]);
				if (beeat[x]!=-1 && eat[y]==-1)
					eat[y]=beeat[x];
				else if (beeat[x]==-1 && eat[y]!=-1)
					beeat[x]=eat[y];
				else if (beeat[x]!=-1 && eat[y]!=-1)
					merge(beeat[x],eat[y]);
			}
		}
	}
	printf("%d\n",fake);
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
int merge(int i,int j)
{
	i=root(i);
	j=root(j);
	if (i==j)
		return i;
	if (Parent[i]<Parent[j])
	{
		Parent[i]+=Parent[j];
		Parent[j]=i;
		if (eat[i]==-1 && eat[j]!=-1)
			eat[i]=eat[j];
		else if (eat[i]!=-1 && eat[j]!=-1)
			eat[i]=merge(eat[i],eat[j]);
		if (beeat[i]==-1 && beeat[j]!=-1)
			beeat[i]=beeat[j];
		else if (beeat[i]!=-1 && beeat[j]!=-1)
			beeat[i]=merge(beeat[i],beeat[j]);
		return i;
	}
	else 
	{
		Parent[j]+=Parent[i];
		Parent[i]=j;
		if (eat[j]==-1 && eat[i]!=-1)
			eat[j]=eat[i];
		else if (eat[i]!=-1 && eat[j]!=-1)
			eat[j]=merge(eat[i],eat[j]);
		if (beeat[j]==-1 && beeat[i]!=-1)
			beeat[j]=beeat[i];
		else if (beeat[i]!=-1 && beeat[j]!=-1)
			beeat[j]=merge(beeat[i],beeat[j]);
		return j;
	}
}
