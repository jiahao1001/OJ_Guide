#include <stdio.h>
int main()
{
	int n, m, i, res = 0;
	scanf("%d %d", &n, &m);
	int *num = new int[n], *color = new int[n], **cnt = new int*[2], **sum = new int*[2];
	cnt[0] = new int[m]; cnt[1] = new int[m]; sum[0] = new int[m]; sum[1] = new int[m];
	for (i = 0; i<m; ++i)
	{
		cnt[0][i] = 0;
		cnt[1][i] = 0;
		sum[0][i] = 0;
		sum[1][i] = 0;
	}
	for (i = 0; i<n; ++i) scanf("%d", &num[i]);
	for (i = 0; i<n; ++i)
	{
		scanf("%d", &color[i]);
		--color[i];
		++cnt[i % 2][color[i]];
		sum[i % 2][color[i]] += num[i];
	}
	for (i = 0; i<n; ++i) res = (res + ((i + 1) % 10007)*(((sum[i % 2][color[i]] % 10007) + ((num[i] % 10007)*(cnt[i % 2][color[i]] + 10005) % 10007)) % 10007)) % 10007;
	printf("%d", res);
	delete[] num;
	delete[] color;
	delete[] cnt[0];
	delete[] cnt[1];
	delete[] sum[0];
	delete[] sum[1];
	delete[] cnt;
	delete[] sum;
}
