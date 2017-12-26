#include<stdio.h>
#include<string.h>
char stone[1000][30],chest[100][30];
char link[100][9][30];
int num[100],n,m,che;
int flag1[100]={0},flag2[100]={0};
int dfs(int p);
int main()
{
	int i,j,k,p,q,c;
	char str[300];
	scanf("%d%d",&n,&m);
	while (n!=0 || m!=0)
	{
		gets(str);
		for (i=0;i<n;i++)
			gets(stone[i]);
		for (j=0;j<m;j++)
		{
			gets(str);
			for (k=0,p=0,q=0;str[k]!=':';k++)
			{
				if (str[k]==',')
				{
					link[j][p][q]='\0';
					p++;
					q=0;
					k++;
				}
				else link[j][p][q++]=str[k];
			}
			link[j][p][q]='\0';
			num[j]=p+1;
			for (q=0,k+=2;str[k]!='\0';k++)
				chest[j][q++]=str[k];
			chest[j][q]='\0';
			if (strcmp(chest[j],"Sorcerer's Stone")==0)
				c=j;
		}
		che=1;
		flag1[c]=1;
		flag2[c]=1;
		printf("%d\n",dfs(c));	
		memset(flag1,0,sizeof(flag1));
		memset(flag2,0,sizeof(flag2));
		scanf("%d%d",&n,&m);
	}
	return 0;
}
int dfs(int p)
{
	int i,j;
	for (i=0;i<num[p];i++)
	{
		for (j=0;j<n;j++)
			if (!strcmp(link[p][i],stone[j]))
				break;
		if (j==n)
		{
			for (j=0;j<m;j++)
			{
				if (flag1[j]==0 && strcmp(link[p][i],chest[j])==0)
				{
					flag1[j]=1;
					if (dfs(j)==-1)
						return -1;
					else {
						if (flag2[j]==0)
							che++;
						flag2[j]=1;
						flag1[j]=0;
						break;
					}
				}
			}
			if (j==m)
				return -1;
		}
	}
	return che;
}
