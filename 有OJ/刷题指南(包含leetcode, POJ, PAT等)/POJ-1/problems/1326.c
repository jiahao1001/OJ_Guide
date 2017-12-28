#include <stdio.h>
#include <string.h>
int main()
{
	int mile,total;
	char s[100],t[100];
	scanf("%s",s);
	while (strcmp(s,"#")!=0)
	{
		total=0;
		while (strcmp(s,"0")!=0)
		{
			scanf("%s%d%s",s,&mile,t);
			if (t[0]=='F')
				total+=mile*2;
			else if (t[0]=='B')
				total+=mile+(mile+1)/2;
			else if (mile<500)
				total+=500;
			else total+=mile;
			scanf("%s",s);
		}
		printf("%d\n",total);
		scanf("%s",s);
	}
	return 0;
}
