#include<iostream>
#define MN 401
bool GE[MN][MN],check[MN];
int h,w,q,point[MN][2],map[40][10];
int match[MN],min,x,y;
bool DFS(int p);
void construct();
int main()
{
	int i,j,k,n,s;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		q=1;
		scanf("%d%d",&h,&w);
		for (j=0;j<h;j++)
		{
			getchar();
			for (k=0;k<w;k++)
			{
				if (getchar()=='*')
					map[j][k]=q++;
				else map[j][k]=0;
			}
		}
		memset(GE,false,sizeof(GE));
		x=1;
		y=q-1;
		for (j=0;j<h;j++)
		{
			for (k=0;k<w;k++)
			{
				if (map[j][k]>0)
				{
					if ((j+k)%2==0)
					{
						point[x][0]=j;
						point[x][1]=k;
						map[j][k]=x++;
					}
					else{
						point[y][0]=j;
						point[y][1]=k;
						map[j][k]=y--;
					}
				}
			}
		}
		construct();
		memset(match,-1,sizeof(match));
		s=0;
		for(k=1;k<x;k++)
		{
			memset(check,false,sizeof(check));
			if (DFS(k))
				s++;
		}
		min=q-1-s;
		printf("%d\n",min);
	}
	return 0;
}
bool DFS(int p)
{
	int i,t,a,b;
	if (p<x)
		a=x,b=q;
	else a=1,b=x;
	for(i=a;i<b;i++)
	{
		if (GE[i][p] && !check[i])
		{
			check[i]=true;
			t=match[i];
			match[i]=p;
			if (t==-1 || DFS(t))
				return true;
			match[i]=t;
		}
	}
	return false;
}
void construct()
{
	int i,p,a,b;
	for (i=1;i<q;i++)
	{
		a=point[i][0];
		b=point[i][1];
		if (a>0 && (p=map[a-1][b])>0)
			GE[i][p]=true;
		if (a<h-1 && (p=map[a+1][b])>0)
			GE[i][p]=true;
		if (b>0 && (p=map[a][b-1])>0)
			GE[i][p]=true;
		if (b<w-1 && (p=map[a][b+1])>0)
			GE[i][p]=true;
	}
}
