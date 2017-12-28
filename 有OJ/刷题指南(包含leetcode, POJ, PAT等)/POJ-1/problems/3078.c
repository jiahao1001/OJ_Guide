#include<stdio.h>
#include<string.h>
char s[30][100];
char ans[30][100];
int pos[30], sign[30], q[30];
int main()
{
	int t, u, tt;
	int i;
	int n, m, a, b;
	scanf ("%d", &tt);
	for (u = 0; u < tt; u++)
	{
		memset (pos, 0, sizeof (pos));
		memset (sign, 0, sizeof (sign));
		scanf ("%d%d", &n, &m);
		for (i = 1; i <= n; i++) scanf ("%s", s[i]);
		for (i = 0; i < m; i++)
		{
			scanf ("%d%d", &a, &b);
			pos[a] = b;
			sign[b] = 1;
		}
		t = 0;
		for (i = 1; i <= n; i++)
			if (!sign[i]) q[t++] = i;
		t = 0;
		for (i = 1; i <= n; i++)
			if (pos[i] == 0) pos[i] = q[t++];
		for (i = 1; i <= n; i++)
			strcpy (ans[pos[i]], s[i]);
		for (i = 1; i <= n; i++)
			printf ("%s ", ans[i]);
		printf ("\n");
	}
	return 0;
}
