#include<iostream>
#define MN 384
bool check[MN];
bool hide[MN][MN]={false};
int match[MN],num,n;
bool DFS(int p);
int main()
{
	int save,i,j,a,b;
	while (scanf("%d",&n)!=EOF)
	{
		num=84+n;
		for (i=84;i<num;i++)
		{
			scanf("%d",&save);
			for (j=0;j<save;j++)
			{
				scanf("%d%d",&a,&b);
				a=12*a+b-13;
				hide[i][a]=true;
				hide[a][i]=true;
			}
		}
		memset(match,-1,sizeof(match));
		save=0;
		for(i=0;i<84;i++)
		{
			memset(check,false,sizeof(check));
			if (DFS(i))
				save++;
		}
		printf("%d\n",save);
		memset(hide,false,sizeof(hide));
	}
	return 0;
}
bool DFS(int p)
{
	int i,t,a,b;
	if (p<84)
		a=84,b=num;
	else a=0,b=84;
	for(i=a;i<b;i++)
	{
		if (hide[i][p] && !check[i])
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
