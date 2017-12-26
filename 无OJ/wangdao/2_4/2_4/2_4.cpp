#include<stdio.h>
#include<algorithm>
using namespace std;
struct E
{
	char name[101];
	int age;
	int score;
}buf[1000];
bool cmp(E a, E b)
{
	if (a.score != b.score)
		return (a.score < b.score);
	int tmp = strcmp(a.name, b.name);
	if (tmp != 0)
		return tmp < 0;
	else
		return a.age < b.age;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s%d%d", buf[i].name, &buf[i].age, &buf[i].score);
		}
		sort(buf, buf + n, cmp);
		for (int i = 0; i < n; i++)
		{
			printf("%s %d %d\n", buf[i].name, buf[i].age, buf[i].score);
		}
	}
	return 0;
}