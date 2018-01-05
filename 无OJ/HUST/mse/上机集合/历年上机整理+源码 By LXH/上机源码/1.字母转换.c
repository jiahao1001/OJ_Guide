/*
		任意输入一串字符,将下标为奇数的小写字母转
	换为大写(编号从0开始,若该位置上不是字母,则不
	转换).举例:若输入abc4Efg,则应输出aBc4EFg(字符串数组)
*/
#include <stdio.h>
#include <string.h>

#define N 80

int main()
{
	char str[N];
	int  i;

	printf("Input: ");
	scanf("%s", str);

	for(i=0; i<(int)strlen(str); i++)
	{
		if(i%2 &&
			str[i] > 'a' &&
			str[i] < 'z')
		{
			str[i] = (char)(str[i] + 'A' - 'a');
		}
	}

	printf("Output: %s\n", str);

	return 0;
}