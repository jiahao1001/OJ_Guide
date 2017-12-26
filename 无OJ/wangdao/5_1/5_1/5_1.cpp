#include<stdio.h>
using namespace std;
#define N 1000
int Tree[N];

int findRoot(int x)
{
	if (Tree[x] == -1)return x;
	else
	{
		int tmp = findRoot(Tree[x]);
		Tree[x] = tmp;
		return tmp;
	}
}

int main()
{
	int n, m;
	while (scanf("%d", &n) != EOF&&n != 0)
	{
		scanf("%d", &m);
		for (int i = 1; i <= n; i++)Tree[i] = -1;
		while (m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			a = findRoot(a);
			b = findRoot(b);
			if (a != b)
			{
				Tree[a] = b;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (Tree[i] == -1)ans++;
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}
