#include<stdio.h>
#include<string.h>
char s[100], t[100], r[100];
void reverse(char str[])
{
	int len = strlen(str) - 1, i;
	char temp;
	for (i = 0; i < len; i++)
	{
		temp = str[i];
		str[i] = str[len];
		str[len] = temp;
		len--;
	}
}
void addition()
{
	int ls = strlen(s), lt = strlen(t);
	int i, c = 0;
	for (i = 0; i < ls && i < lt; i++)
	{
		r[i] = c + s[i] + t[i] - '0';
		if (r[i] > '1')
		{
			r[i] -= 2;
			c = 1;
		}
		else c = 0;
	}
	while (i < ls)
	{
		r[i] = c + s[i];
		if (r[i] > '1')
		{
			r[i] -= 2;
			c = 1;
		}
		else c = 0;
		i++;
	}
	while (i < lt)
	{
		r[i] = c + t[i];
		if (r[i] > '1')
		{
			r[i] -= 2;
			c = 1;
		}
		else c = 0;
		i++;
	}
	if (c == 1)
		r[i++] = '1';
	else {
		while (i > 1 && r[i - 1] == '0')
			i--;
	}
	r[i] = '\0';
}
int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%s%s", s, t);
		reverse(s);
		reverse(t);
		addition();
		reverse(r);
		printf("%d %s\n", i, r);
	}
	return 0;
}
