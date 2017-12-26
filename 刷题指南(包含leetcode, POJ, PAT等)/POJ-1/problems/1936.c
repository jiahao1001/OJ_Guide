#include<stdio.h>
int main()
{
	int i,j,k;
	char s[100000],t[100000];
	while (scanf("%s %s",s,t)!=EOF)
	{
		j=0;
		for (i=0;t[i]!='\0';i++)
		{
			if (s[j]=='\0')
				break;
			if (s[j]==t[i])
				j++;
		}
		if (s[j]=='\0')
			printf("Yes\n");
		else printf("No\n");
	}			
	return 0;
}
