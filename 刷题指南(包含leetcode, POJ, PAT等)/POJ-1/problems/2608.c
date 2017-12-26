#include <stdio.h>
int main()
{
	int i;
	char s[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2},t[21],c;
	while (scanf("%s",t)!=EOF)
	{
		c=-1;
		for (i=0;t[i]!='\0';i++)
		{
			if (s[t[i]-'A']!=0 && s[t[i]-'A']!=c)
				printf("%d",s[t[i]-'A']);
			c=s[t[i]-'A'];
		}	
		printf("\n");
	}
	return 0;
}
