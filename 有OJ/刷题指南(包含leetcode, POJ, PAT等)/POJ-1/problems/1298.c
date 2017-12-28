#include<stdio.h>
#include<string.h>
int main()
{
	int i;
	char s[201];
	gets(s);
	while (strcmp(s,"START")==0)
	{
		gets(s);
		while (strcmp(s,"END")!=0)
		{
			for (i=0;s[i]!='\0';i++)
			{
				if (s[i]>'E' && s[i]<='Z')
					printf("%c",s[i]-5);
				else if (s[i]>='A' && s[i]<'F')
					printf("%c",s[i]+21);
				else printf("%c",s[i]);
			}
			printf("\n");
			gets(s);
		}
		gets(s);
	}
	return 0;
}
