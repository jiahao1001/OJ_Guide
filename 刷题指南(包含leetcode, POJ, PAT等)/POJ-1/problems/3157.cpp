#include<stdio.h>
#include<string.h>
char str[200];
bool cpp=false,java=false,error=false;
int main()
{
	int i,j,len;
	gets(str);
	len=strlen(str);
	if (str[0]>'z' || str[0]<'a')
		error=true;
	else {
		for (i=1;i<len;i++)
		{
			if (str[i]>='A' && str[i]<='Z')
				java=true;
			if (str[i]=='_')
			{
				if (str[i-1]>='a' && str[i-1]<='z' && i+1<len && str[i+1]>='a' && str[i+1]<='z')
					cpp=true;
				else error=true;
			}
		}
	}
	if (error==true || (cpp==true && java==true))
		printf("Error!\n");
	else {
		for (i=0;i<len;i++)
		{
			if (str[i]>='A' && str[i]<='Z')
			{
				putchar('_');
				putchar(str[i]-'A'+'a');
			}
			else if (str[i]=='_')
			{
				i++;
				putchar(str[i]-'a'+'A');
			}
			else putchar(str[i]);
		}
		putchar('\n');
	}
	return 0;
}
