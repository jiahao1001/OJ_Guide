#include<stdio.h>
#define MAX	501
#define ROUND	2000
struct round{
	int d;
	int x;
	int y;
}Round[ROUND];
int P[MAX],Q[MAX],R[MAX];
int n,m;
int Rochambeau(int judge);
int root(int i);
int  merge(int i,int j);
int main()
{
	int i,x,y;
	int s,fake;
	char ch;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		for (i=0;i<m;i++)
		{
			scanf("%d%c%d",&x,&ch,&y);
			x++;
			y++;
			if (ch=='<')
			{
				Round[i].d=2;
				Round[i].x=y;
				Round[i].y=x;
			}
			else if (ch=='>')
			{
				Round[i].d=2;
				Round[i].x=x;
				Round[i].y=y;
			}
			else if (ch=='=')
			{
				Round[i].d=1;
				Round[i].x=x;
				Round[i].y=y;
			}
		}
		for (s=0,i=1,fake=-1;i<=n;i++)
		{
			x=Rochambeau(i);
			if (x==-1)
			{
				if (s==0)
					s=i;
				else break;
			}
			else if (x>fake)
				fake=x;
		}
		if (i<=n)
			printf("Can not determine\n");
		else if (s==0)
			printf("Impossible\n");
		else  printf("Player %d can be determined to be the judge after %d lines\n",s-1,fake+1);
	}
	return 0;
}
int Rochambeau(int jud)
{
	int i,j,d,x,y;
	for (i=0;i<=n;i++)
	{
		P[i]=-1;
		Q[i]=-1;
		R[i]=-1;
	}
	for (i=0;i<m;i++)
	{
		x=Round[i].x;
		y=Round[i].y;
		d=Round[i].d;
		if (x==jud || y==jud)
			continue;
		x=root(x);
		y=root(y);
		if (Q[x]!=-1)
			Q[x]=root(Q[x]);
		if (R[x]!=-1)
			R[x]=root(R[x]);
		if (Q[y]!=-1)
			Q[y]=root(Q[y]);
		if (R[y]!=-1)
			R[y]=root(R[y]);
		if (d==1)
		{
			if (Q[x]==y || Q[y]==x )
				return i;
			else merge(x,y);
		}
		else{
			if (x==y || Q[y]==x)
				return i;
			else {
				if (Q[x]==-1)
					Q[x]=y;
				else merge(y,Q[x]);
				if (R[y]==-1)
					R[y]=x;
				else merge(x,R[y]);
				if (R[x]!=-1 && Q[y]==-1)
					Q[y]=R[x];
				else if (R[x]==-1 && Q[y]!=-1)
					R[x]=Q[y];
				else if (R[x]!=-1 && Q[y]!=-1)
					merge(R[x],Q[y]);
			}
		}
	}
	return -1;
}
int root(int i)
{
	int r,p;
	for (r=i;P[r]>0;r=P[r]);
	while (i!=r)
	{
		p=i;
		i=P[i];
		P[p]=r;
	}	
	return r;
}
int merge(int i,int j)
{
	i=root(i);
	j=root(j);
	if (i==j)
		return i;
	if (P[i]<P[j])
	{
		P[i]+=P[j];
		P[j]=i;
		if (Q[i]==-1 && Q[j]!=-1)
			Q[i]=Q[j];
		else if (Q[i]!=-1 && Q[j]!=-1)
			Q[i]=merge(Q[i],Q[j]);
		if (R[i]==-1 && R[j]!=-1)
			R[i]=R[j];
		else if (R[i]!=-1 && R[j]!=-1)
			R[i]=merge(R[i],R[j]);
		return i;
	}
	else 
	{
		P[j]+=P[i];
		P[i]=j;
		if (Q[j]==-1 && Q[i]!=-1)
			Q[j]=Q[i];
		else if (Q[i]!=-1 && Q[j]!=-1)
			Q[j]=merge(Q[i],Q[j]);
		if (R[j]==-1 && R[i]!=-1)
			R[j]=R[i];
		else if (R[i]!=-1 && R[j]!=-1)
			R[j]=merge(R[i],R[j]);
		return j;
	}
}
