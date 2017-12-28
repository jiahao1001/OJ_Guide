#include <stdio.h>
int main()
{
	int i,j,k,l[26]={0};
	char s[73];
	for (i=0;i<4;i++)
	{
		gets(s);
		for (j=0;s[j]!='\0';j++)
		{
			if (s[j]>='A' && s[j]<='Z')
				l[s[j]-'A']++;
		}
	}
	j=l[0];
	for (i=1;i<26;i++)
	{
		if (l[i]>j)
			j=l[i];
	}
	for (i=j;i>0;i--)
	{
		for (k=0;k<25;k++)
		{
			if (l[k]==i)
			{
				l[k]--;
				printf("* ");
			}
			else printf("  ");
		}
		if (l[k]==i)
		{
			l[k]--;
			printf("*\n");
		}
		else printf(" \n");
	}
	for (i=0;i<25;i++)
		printf("%c ",'A'+i);
	printf("Z\n");
	return 0;
}
