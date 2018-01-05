#include<stdio.h>
int main()
{ //用hash表来解决此问题
	int n;
	int x;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int Hash[101]={0};
		//这句一定要放在while循环内,每次都重新初始化
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			Hash[x]++;
		}	
		int find;
		scanf("%d",&find);
		printf("%d\n",Hash[find]);
	}
	return 0;
}