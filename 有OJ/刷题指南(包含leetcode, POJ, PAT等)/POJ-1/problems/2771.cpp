#include<stdio.h>
#include<string.h>
#define MAX 500
bool Check[MAX];
bool Hide[MAX][MAX]={false};
int Match[MAX],n,boys,height[500];
char music[500][100],sport[500][100];
bool DFS(int p);
bool compare(int boy,int girl);
int main()
{
	int t,i,j,k,a,b,h,Save;
	char str[20];
	scanf("%d",&t);
	for (j=0;j<t;j++)
	{
		scanf("%d",&n);
		memset(Hide,false,sizeof(Hide));
		a=0;
		b=n-1;
		for (i=0;i<n;i++)
		{
			scanf("%d%s",&h,str);
			if (str[0]=='M')
			{
				k=a;
				a++;
			}
			else {
				k=b;
				b--;
			}
			height[k]=h;
			scanf("%s%s",music[k],sport[k]);
		}
		boys=a;
		for (i=0;i<boys;i++)
		{
			for (k=boys;k<n;k++)
			{
				if (compare(i,k)==true)
				{
					Hide[i][k]=true;
					Hide[k][i]=true;
				}
			}
		}
		Save=0;
		memset(Match,-1,sizeof(Match));
		for(i=0;i<boys;i++)
		{
			memset(Check,false,sizeof(Check));
			if (DFS(i))
				Save++;
		}
		printf("%d\n",n-Save);
	}
	return 0;
}
bool DFS(int p)
{
	int i,t,a,b;
	if (p<boys)
		a=boys,b=n;
	else a=0,b=boys;
	for(i=a;i<b;i++)
	{
		if (Hide[i][p] && !Check[i])
		{
			Check[i]=true;
			t=Match[i];
			Match[i]=p;
			if (t==-1 || DFS(t))
				return true;
			Match[i]=t;
		}
	}
	return false;
}
bool compare(int boy,int girl)
{
	if (height[boy]-height[girl]>40 || height[girl]-height[boy]>40)
		return false;
	if (strcmp(music[boy],music[girl])!=0)
		return false;
	if (strcmp(sport[boy],sport[girl])==0)
		return false;
	return true;
}
