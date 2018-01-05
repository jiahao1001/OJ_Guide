#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> edge[501]; 
//邻接表，只保留邻接的编号，相当于edge[i].next
queue<int> Q;
int main()
{
	int inDegree[501]; //每个结点的入度
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0) 
			break;
		int i;
		for(i=0;i<n;i++) //本题采用结点编号为0--n-1
		{
			inDegree[i] = 0;
			edge[i].clear();
		}
		while(m--!=0)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			//有向图，由a指向b
			inDegree[b]++;
			edge[a].push_back(b); //把b添加到a的邻接链表中
		}
		while(Q.empty()!=true)
			Q.pop(); //清除上一组数据
		for(i=0;i<n;i++)
			if(inDegree[i] == 0)
				Q.push(i); //把入度为0的结点暂存队列;用栈也可以
		int cnt = 0; //计数确定的拓扑序列的个数
		while(Q.empty()!=true)
		{ //要把入度为0的结点都取出来
			int nowP = Q.front();
			Q.pop();
			cnt++;
			for(i=0;i<edge[nowP].size();i++) //去掉该结点，修正入度
			{
				inDegree[edge[nowP][i]]--;
				if(inDegree[edge[nowP][i]] == 0)
					Q.push(edge[nowP][i]);
			}
		}
		if(cnt == n)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}