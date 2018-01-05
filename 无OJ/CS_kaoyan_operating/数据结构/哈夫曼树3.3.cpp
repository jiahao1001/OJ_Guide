#include<queue>
#include<stdio.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > Q;
//小顶堆，注意：最后“> >”中间要加空格
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		while(Q.empty()==false) Q.pop();
		for(i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			Q.push(x);
		}
		int ans = 0; //最后的结果
		while(Q.size()>1)
		{
			int a = Q.top();
			Q.pop();
			int b = Q.top();
			Q.pop();
			ans += a+b; // += 不能分开
			Q.push(a+b);
			//不是Q.push(ans)
		}
		printf("%d\n",ans);
	}
	return 0;
}