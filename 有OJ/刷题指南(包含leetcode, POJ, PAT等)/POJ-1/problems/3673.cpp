#include<stdio.h>
char s[100],t[100];
int main()
{
	int i,j;
	int sum=0;
	scanf("%s%s",s,t);
	for (i=0;s[i]!='\0';i++)
		for (j=0;t[j]!='\0';j++)
			sum+=(s[i]-'0')*(t[j]-'0');
	printf("%d\n",sum);
	return 0;
}