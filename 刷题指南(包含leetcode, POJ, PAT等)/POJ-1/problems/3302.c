#include<stdio.h>
char s[200],t[200];
int main()
{
	int test,i,j,k;
	scanf("%d\n",&test);
	for (i=0;i<test;i++)
	{
		scanf("%s%s",s,t);
		for (j=0,k=0;s[j]!='\0' && t[k]!='\0';j++)
		{
			if (s[j]==t[k])
				k++;
		}
		if (t[k]=='\0')
			printf("YES\n");
		else {
			for (k=0,j--;j>=0 && t[k]!='\0';j--)
			{
				if (s[j]==t[k])
					k++;
			}
			if (t[k]=='\0')
				printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
