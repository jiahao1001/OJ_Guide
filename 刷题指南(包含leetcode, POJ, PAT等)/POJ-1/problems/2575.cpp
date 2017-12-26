#include<stdio.h>
#include<string.h>
bool flag[3000];
int fab(int i,int j)
{
	if (i>j)
		return i-j;
	else return j-i;
}
int main()
{
	int n,i,a,b,c;
	bool jolly;
	while (scanf("%d",&n)!=EOF)
	{
		scanf("%d",&a);
		memset(flag,false,sizeof(flag));
		jolly=true;
		for (i=1;i<n;i++)
		{
			scanf("%d",&b);
			c=fab(a,b);
			if (c>0 && c<n && flag[c]==false)
				flag[c]=true;
			else jolly=false;
			a=b;
		}
		if (jolly==true)
			printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}
