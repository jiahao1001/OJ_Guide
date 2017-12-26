#include<stdio.h>
#include<string.h>
int m,n;
bool Step[250][250];
char map[250][250];
int dfs(int i,int j,int step)
{
	int a=10000,b=10000;
	Step[i][j]=true;
	while (i<n-1 && map[i+1][j]=='S')
	{
		i++;
		Step[i][j]=true;
		step++;
	}
	if (i==n-1)
		return step;
	if (j>0 && map[i][j-1]=='S' && Step[i][j-1]==false)
		a=dfs(i,j-1,step+1);
	if (j<m-1 && map[i][j+1]=='S' && Step[i][j+1]==false)
		b=dfs(i,j+1,step+1);
	if (a>b)
		return b;
	else return a;
}
int main()
{
	int i,j,k,min;
	scanf("%d%d",&n,&m);
	while (m!=0 || n!=0)
	{
		for (i=0;i<n;i++)
		{
			scanf("%s",map[i]);
			for (j=m-2;j>=0;j--)
				if (map[i][j]=='S' && ((i!=0 && i!=n-1) || j!=m-2))
					map[i][j+1]='S';
		}
		memset(Step,false,sizeof(Step));
		for (j=0;j<m;j++)
			if (map[0][j]=='S')
				break;
		min=dfs(0,j,1);
		if (j!=m-2)
		{
			memset(Step,false,sizeof(Step));
			k=dfs(0,j+1,1);
			if (min>k)
				min=k;
		}
		printf("%d\n",min);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
