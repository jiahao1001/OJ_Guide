#include<stdio.h>
#include<string.h>
#define len 60
int count;
char s[15][80];
char ans[15][80];
char goal[80];
int find (int start,int l,int t)
{
	int i,j,st;
	for (st=0;st<=len-l;st++)
	{
		for (i=start,j=st;j<l+st;j++,i++)
			if (goal[i]!=s[t][j])
				break;
		if (j==st+l)
			return 1;
	}
	return 0;
}
void copy (int start,int l)
{
	int i,j;
	for (i=start,j=0;j<l;i++,j++)
		ans[count][j]=goal[i];
	count++;
}
int main ()
{
	int t,u,i,j,n;
	int l,f,finish;
    char tmp[80];
	scanf("%d",&t);
	for (u=0;u<t;u++)
	{
		memset(ans,'\0',sizeof (ans));
		scanf ("%d",&n);
		scanf ("%s",goal);
		finish=0;
		for (i=0;i<n-1;i++)
			scanf ("%s",s[i]);
		for (l=len;l>=3;l--)
		{
			count=0;
			for (i=0;i<=len-l;i++)
			{
				for (j=0;j<n-1;j++)
				{
					f=find(i,l,j);
					if (!f) 
						break;
				}
				if (j==n-1)
				{
					copy(i,l);
					finish=1;
				}
			}
			if (finish)
			{
				for (i=0;i<count;i++)
				{
					for (j=i+1;j<count;j++)
					{
						if (strcmp(ans[i],ans[j])>0)
						{
							strcpy(tmp,ans[i]);
							strcpy(ans[i],ans[j]);
							strcpy(ans[j],tmp);
						}
					}
				}
				printf("%s\n",ans[0]);
				break;
			}
		}
		if (!finish) 
			printf("no significant commonalities\n");
	}
	return 0;
}
