#include<iostream>
#define MN 1024
bool GE[MN][MN]={false},check[MN];
int q,point[MN][2],map[32][32]={0};
int match[MN],a,b,m,n;
bool DFS(int p);
void construct();
int main()
{
	int i,j,k,s;
	scanf("%d%d%d",&m,&n,&k);
	for (i=0;i<k;i++)
	{
		scanf("%d%d",&b,&a);
		map[a-1][b-1]=-1;
	}
	q=m*n-k;
	a=0;
	b=q-1;
	for (i=0;i<m;i++)
	{
		for (j=0;j<n;j++)
		{
			if (map[i][j]>=0)
			{
				if ((i+j)%2==0)
				{
					point[a][0]=i;
					point[a][1]=j;
					map[i][j]=a++;
				}
				else{
					point[b][0]=i;
					point[b][1]=j;
					map[i][j]=b--;
				}
			}
		}
	}
	if (k%2!=0 || a+a!=q)
		printf("NO\n");
	else{
		construct();
		memset(match,-1,sizeof(match));
		s=0;
		for(i=0;i<a;i++)
		{
			memset(check,false,sizeof(check));
			if (DFS(i))
				s++;
		}
		if (q==s+s)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
bool DFS(int p)
{
	int i,t,x,y;
	if (p<a)
		x=a,y=q;
	else x=0,y=a;
	for(i=x;i<y;i++)
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
	int i,p,x,y;
	for (i=0;i<a;i++)
	{
		x=point[i][0];
		y=point[i][1];
		if (x>0 && (p=map[x-1][y])>=0)
			GE[p][i]=true,GE[i][p]=true;
		if (x<m-1 && (p=map[x+1][y])>=0)
			GE[p][i]=true,GE[i][p]=true;
		if (y>0 && (p=map[x][y-1])>=0)
			GE[p][i]=true,GE[i][p]=true;
		if (y<n-1 && (p=map[x][y+1])>=0)
			GE[p][i]=true,GE[i][p]=true;
	}
}
