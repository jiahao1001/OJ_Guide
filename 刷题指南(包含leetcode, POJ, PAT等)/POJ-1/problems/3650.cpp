#include<stdio.h>
#include<string.h>
char s[100];
int main()
{
	int i;
	int sum=0;
	gets(s);
	while (strcmp(s,"#")!=0)
	{
		for (i=0;s[i]!='\0';i++)
		{
			if (s[i]==' ')
				printf("%%20");
			else if (s[i]=='!')
				printf("%%21");
			else if (s[i]=='$')
				printf("%%24");
			else if (s[i]=='%')
				printf("%%25");
			else if (s[i]=='(')
				printf("%%28");
			else if (s[i]==')')
				printf("%%29");
			else if (s[i]=='*')
				printf("%%2a");
			else putchar(s[i]);
		}
		putchar('\n');
		gets(s);
	}
	return 0;
}
