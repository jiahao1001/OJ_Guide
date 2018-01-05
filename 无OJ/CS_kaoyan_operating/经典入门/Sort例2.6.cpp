#include<stdio.h>
#define OFFSET 500000
int Hash[1000001];
int main()
{
	int n,m;
	int x;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int i;
		for(i=500000;i>=-500000;i--)
			Hash[i+OFFSET] = 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			Hash[x+OFFSET]=1;
		}
		for(i=500000;i>=-500000;i--)
		{ //从大到小输出前m个			
			if(Hash[i+OFFSET]){
				printf("%d",i);
			m--;
			//这几句对m的操作一定要放在大if的里面
			if(m!=0)
				printf(" ");
			else{
				printf("\n");
				break;
				}
			}

		}
	}
	return 0;
}