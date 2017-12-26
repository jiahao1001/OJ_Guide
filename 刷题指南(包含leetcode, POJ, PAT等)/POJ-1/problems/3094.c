#include<stdio.h>
#include<string.h>
char str[300];
int main()
{
	int i,sum;
	gets(str);
	while (strcmp(str,"#")!=0)
	{
		sum=0;
		for (i=0;str[i]!='\0';i++)
			if (str[i]>='A' && str[i]<='Z')
				sum+=(i+1)*(str[i]-'A'+1);
		printf("%d\n",sum);
		gets(str);
	}
	return 0;
}
