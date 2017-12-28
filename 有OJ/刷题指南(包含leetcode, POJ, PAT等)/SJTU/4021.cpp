#include <cstdio>
int health[100];
struct Move
{
	int mp, damage;
};
Move moves[2][100];
int n, single = 0, all = 0, maxHP = 0;
int hp[2][100001];
void dp(int* res, Move* mov, int num)
{
	res[0] = 0;
	int i, min, j, tmp;
	for (i = 1; i <= maxHP; ++i)
	{
		min = 1000000000;
		for (j = 0; j<num; ++j)
		{
			if (i - mov[j].damage <= 0) tmp = mov[j].mp;
			else tmp = res[i - mov[j].damage] + mov[j].mp;
			if (tmp<min) min = tmp;
		}
		res[i] = min;
	}
}
int main()
{
	//freopen("4021.in","r",stdin);
	int M, i, j, x, y;
	char s[31];
	scanf("%d", &n);
	for (i = 0; i<n; ++i)
	{
		scanf("%d", &health[i]);
		if (health[i]>maxHP) maxHP = health[i];
	}
	scanf("%d", &M);
	for (i = 0; i<M; ++i)
	{
		scanf("%s", s);
		scanf("%d %s %d", &x, s, &y);
		if (y == 0) continue;
		else if (x == 0)
		{
			printf("0");
			return 0;
		}
		if (s[0] == 'S')
		{
			moves[0][single].mp = x;
			moves[0][single].damage = y;
			++single;
		}
		else
		{
			moves[1][all].mp = x;
			moves[1][all].damage = y;
			++all;
		}
	}
	dp(hp[0], moves[0], single);
	dp(hp[1], moves[1], all);
	long long min = 10000000000000000, tmp;
	for (i = 0; i <= maxHP; ++i)
	{
		tmp = hp[1][i];
		for (j = 0; j<n; ++j) if (i<health[j]) tmp += hp[0][health[j] - i];
		if (tmp<min) min = tmp;
	}
	printf("%lld", min);
}
