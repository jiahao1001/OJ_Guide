/*
	给定任意俩组字符串S1和S2,
请编程输出他们间的最大相同子串.
*/
#include <stdio.h>
#include <string.h>

#define N 40

char subStr1[N], subStr2[N];

//取子串
void SubString(char *src, char *sub, int s, int e)
{
	int i;

	for(i=s; i<e; i++)
	{
		sub[i-s] = src[i];
	}

	sub[i-s] = '\0';
}

//求最大公共子串
char* MaxSubString(char *str1, char *str2)
{
	int len1 = (int)(strlen(str1));
	int len2 = (int)(strlen(str2));
	//求长度最小者
	int len = len1 < len2 ? len1 : len2;

	int i, j;

	//长度从大到小遍历
	while(len)
	{
		for(i=0; i<len1-len+1; i++)
		{
			for(j=0; j<len2-len+1; j++)
			{
				//取子串
				SubString(str1, subStr1, i, i+len);
				SubString(str2, subStr2, j, j+len);

				//子串相等(直接返回)
				if(!strcmp(subStr1, subStr2))
				{
					return subStr1;
				}
			}
		}

		len--;
	}
}

int main()
{
	char str1[N], str2[N];

	printf("S1 = ");
	scanf("%s", str1);

	printf("S2 = ");
	scanf("%s", str2);

	//输出子串
	printf("Max sub string is %s\n", 
		MaxSubString(str1, str2));

	return 0;
}