#include<stdio.h>
#include<string.h>
int weight[101],n,e;
bool G[101][101],flag;
int main()
{
	int i,j,a,b,c;
	int test=1;
	while (scanf("%d",&n),n!=0)
	{
		scanf("%d",&e);
		memset(G,false,sizeof(G));
		memset(weight,0,sizeof(weight));
		for (i=0;i<e;i++)
		{
			scanf("%d%d",&a,&b);
			G[a][b]=true;
			G[b][a]=true;
			weight[a]++;
			weight[b]++;
		}
		for (i=1;i<=n;i++)
		{
			if (weight[i]==1)
			{
				memset(G[i],false,sizeof(G[i]));
				weight[i]=-1;
			}
		}
		flag=true;
		a=0;
		b=0;
		c=0;
		for (i=1;i<=n;i++)
		{
			if (weight[i]!=-1)
			{
				for (j=1;j<=n;j++)
				{
					if (G[i][j]==true && weight[j]==-1)
					{
						G[i][j]=false;
						weight[i]--;
					}
				}
				if (weight[i]>2)
				{
					flag=false;
					break;
				}
				else if (weight[i]==1)
					a++;
				else if (weight[i]==0)
					b++;
				else c++;
			}
		}
		if (flag==true)
		{
			if ((b<=1 && a==0 && c==0) || (b==0 && a==2))
				flag=true;
			else flag=false;
		}
		if (flag==false)
			printf("Graph %d is not a caterpillar.\n",test++);
		else printf("Graph %d is a caterpillar.\n",test++);
	}
	return 0;
}
