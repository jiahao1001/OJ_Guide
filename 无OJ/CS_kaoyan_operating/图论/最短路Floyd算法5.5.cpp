#include<stdio.h>
int ans[101][101];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i,j,k;
		if(n==0 && m==0)
			break;
		for(i=1;i<=n;i++)
		{ //初始化
			for(j=i;j<=n;j++)
				ans[i][j] = -1; // -1为无穷
			ans[i][i] = 0;
		}
		while(m--!=0)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ans[a][b] = ans[b][a] =c;
			//无向图
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
					if(ans[i][k] == -1 || ans[k][j] == -1) 
						continue;
					if(ans[i][j] == -1 || ans[i][k]+ans[k][j] < ans[i][j]) 
						ans[i][j] = ans[i][k]+ans[k][j];
				}
		printf("%d\n",ans[1][n]);
	}
	return 0;
}