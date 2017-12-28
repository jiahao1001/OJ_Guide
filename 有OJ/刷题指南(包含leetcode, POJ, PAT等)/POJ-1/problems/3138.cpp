#include<stdio.h>
int S,T,M,i,j=1,s;
int team[200];
bool flag[200];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&S,&T,&M);
	while (S!=0 || T!=0 || M!=0)
	{
		for (i=0;i<S;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			team[a]=b+c;
			flag[a]=false;
		}
		for (i=0;i<T;i++)
		{
			scanf("%d%d",&a,&b);
			if (b>=M && flag[a]==false)
				flag[a]=true;
		}
		for (i=1,s=0;i<=S;i++)
		{
			s+=team[i];
			if (flag[i]==true)
				s++;
		}
		printf("Case %d: %d\n",j++,s);
		scanf("%d%d%d",&S,&T,&M);
	}
	return 0;
}
