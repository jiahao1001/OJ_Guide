#include<stdio.h>
#include<vector>
using namespace std;
struct E
{
	int next;
	int c;
};
vector<E> edge[101];
bool mark[101];
int Dis[101];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i,j;
		if(n==0 && m==0)
			break;
		for(i=1;i<=n;i++)
			edge[i].clear();
		while(m--!=0)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E tmp;
			tmp.c = c;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
			// 因为是无向图
		}
		for(i=1;i<=n;i++)
		{
			Dis[i] = -1;
			mark[i] = false;
		}
		Dis[1] = 0;
		mark[1] = true;
		int newP = 1; //新加入的结点
		for(i=1;i<n;i++) //控制n-1次循环，遍历剩下的结点   *********
		{	for(j=0;j<edge[newP].size();j++)
			{
				int t = edge[newP][j].next;
				int cost = edge[newP][j].c;
				// 直接edge[newP].是对邻接链表的操作。
				//而edge[newP][j].是对edge[]所指向的结构体E的操作，只有next和c
				//邻接表本来就是二维的
				if(mark[t] == true)
					continue;
				if(Dis[t] == -1 || Dis[t]>Dis[newP]+cost)
					Dis[t] = Dis[newP]+cost;
			}
		int min = 123123123; //要找到最小的
		for(j=1;j<=n;j++)
		{
			if(mark[j] == true) 
				continue;
			if(Dis[j] == -1)
				continue;
			if(Dis[j] < min)
			{
				min = Dis[j];
				newP = j;
			}
		}
		  mark[newP] = true;
		} //***********
		printf("%d\n",Dis[n]);
	}
	return 0;
}