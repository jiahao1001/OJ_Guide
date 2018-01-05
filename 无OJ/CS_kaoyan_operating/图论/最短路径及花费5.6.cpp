#include<stdio.h>
#include<vector>
using namespace std;
struct E
{
	int next;
	int c;  //路径长度
	int cost; //花费 
};
vector<E> edge[1001];
int Dis[1001];
int cost[1001];
bool mark[1001];
int main()
{
	int n,m;
	int S,T;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0) 
			break;
		int i,j;
		for(i=1;i<=n;i++)
			edge[i].clear();
		//初始化
		while(m--!=0)
		{
			int a,b,c,cost;
			//a ,b 为结点号 
			scanf("%d%d%d%d",&a,&b,&c,&cost);
			E tmp;
			tmp.c = c;
			tmp.cost = cost;
			tmp.next = b;
			edge[a].push_back(tmp);
			tmp.next = a;
			edge[b].push_back(tmp);
			//因为是无向图
		}
		scanf("%d%d",&S,&T);
		for(i=1;i<=n;i++)
		{
			Dis[i] = -1;
			mark[i] = false;
			//初始化
		}
		Dis[S] = 0;
		mark[S] = true;
		int newP = S;
		for(i=1;i<n;i++) //控制循环，还有剩余的n-1个
			for(j=0;j<edge[newP].size();j++) 
			//j要从0开始，因为edge[newP][]是从下标0开始的
			{  //要找到一些候选的点
				int t = edge[newP][j].next; // t为下一个结点
				int c = edge[newP][j].c; //路径
				int co = edge[newP][j].cost;
				if(mark[t] == true)
					continue;
				if(Dis[t]==-1 || Dis[t]>Dis[newP]+c || (Dis[t]==Dis[newP]+c && cost[t]>cost[newP]+co))
				{ //更新
					Dis[t] = Dis[newP]+c;
					cost[t] = cost[newP]+co;
				}
				int min = 123123123;
				//现在开始在候选中找最小，然后加入到K集合中
				for(j=1;j<=n;j++)
				{
					if(mark[j] == true) 
						continue;
					if(Dis[j] == -1)
						continue;
					if(Dis[j] < min)
					{
						min = Dis[j];
						newP = j; //这个只是暂时的，要到for循环外面才定下来最小的
					}
				}
				mark[newP] = true; //标记
			}//外for，控制循环
		printf("%d %d\n",Dis[T],cost[T]);
	}
	return 0;
}