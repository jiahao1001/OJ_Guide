#include <stdio.h>
char str[20];
int qu;
int main()
{
	int i,sum=0;
	scanf("%s",str);
	for (i=0;i<9;i++)
	{
		if (str[i]=='?')
			qu=i;
		else sum+=(10-i)*(str[i]-'0');
	}
	if (str[9]=='?')
		qu=9;
	else if (str[9]=='X')
		sum+=10;
	else sum+=str[9]-'0';
	for (i=0;i<10;i++)
	{
		if ((sum+(10-qu)*i)%11==0)
			break;
	}
	if (i<10)
		printf("%d\n",i);
	else if ((sum+10)%11==0)
		printf("X\n");
	else printf("-1\n");
    return 0;
}
