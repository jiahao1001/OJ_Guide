#include<stdio.h>
int N,M,K;
int k;
bool farm[101][101]={false};
void dfs(int p,int q)
{
	farm[p][q]=false;
	k++;
	if (p>1 && farm[p-1][q]==true)
		dfs(p-1,q);
	if (p<N && farm[p+1][q]==true)
		dfs(p+1,q);
	if (q>1 && farm[p][q-1]==true)
		dfs(p,q-1);
	if (q<M && farm[p][q+1]==true)
		dfs(p,q+1);
}
int main()
{
	int i,j,a,b;
	int max=0;
	scanf("%d%d%d",&N,&M,&K);
	for (i=0;i<K;i++)
	{
		scanf("%d%d",&a,&b);
		farm[a][b]=true;
	}
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=M;j++)
		{
			if (farm[i][j]==true)
			{
				k=0;
				dfs(i,j);
				if (k>max)
					max=k;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}
