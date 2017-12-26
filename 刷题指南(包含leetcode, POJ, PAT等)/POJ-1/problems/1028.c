#include<stdio.h>
#include<string.h>
int top = 0, up = 0;
char stack[110][100]={"http://www.acm.org/"};
int main()
{
    char str[100];
	scanf("%s", str);
	while (strcmp(str, "QUIT") != 0)
	{
		if (strcmp(str, "VISIT") == 0)
		{
			scanf("%s", stack[++top]);
			printf("%s\n", stack[top]);
			up = top;
		}
		else if (strcmp(str, "BACK") == 0)
		{
			if (top == 0)
				printf("Ignored\n");
			else printf("%s\n", stack[--top]);
		}
		else if (strcmp(str, "FORWARD") == 0)
		{
			if (top == up)
				printf("Ignored\n");
			else printf("%s\n", stack[++top]);
		}
		scanf("%s", str);
	}
	return 0;
}
