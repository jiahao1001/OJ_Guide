#include<stdio.h>
#define N 1000
int Tree[N];
int findRoot(int x)
{
	if(Tree[x]==-1)
		return x;
	else
	{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}
int main()
{
	int n,m; //n为城镇数，m为道路数
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		scanf("%d",&m);
		int i;
		for(i=1;i<=n;i++) //注意是从1--n
			Tree[i] = -1;
		//初始化都是孤立的点
		int a,b;
		while(m--!=0)
		{
			scanf("%d%d",&a,&b);
			a = findRoot(a);
			b = findRoot(b);
			if(a!=b)
				Tree[a] = b;		
		}
		int ans = 0;
		//要放在while里面，每次重新清零
		for(i=1;i<=n;i++)		
			if(Tree[i]==-1)
				ans++;
		printf("%d\n",ans-1);
		//这个ans要减一
	}
	return 0;
}