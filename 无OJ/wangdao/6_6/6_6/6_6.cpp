#include<stdio.h>
char maze[101][101];
bool mark[101][101];
int n, m;
int go[][2] = { 1, 0, -1, 0, 0, 1, 0, -1, 1, 1, 1, -1, -1, -1, -1, 1 };
void DFS(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if (nx<1 || nx>n || ny<1 || ny>m)
			continue;
		if (maze[nx][ny] == '*')
			continue;
		if (mark[nx][ny] == true)
			continue;
		mark[nx][ny] = true;
		DFS(nx, ny);
	}
	return;
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", maze[i] + 1);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				mark[i][j] = false;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (mark[i][j] == true)
					continue;
				if (maze[i][j] == '*')
					continue;
				DFS(i, j);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
