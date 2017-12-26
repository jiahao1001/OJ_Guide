#include <stdio.h>
int main()
{
	int i;
	char s[26],r[81];
	gets(r);
	for (i=0;i<26;i++)
		s[i]=r[i]-'a';
	gets(r);
	for (i=0;r[i]!='\0';i++)
	{
		if (r[i]>='a' && r[i]<='z')
			printf("%c",s[r[i]-'a']+'a');
		else if (r[i]>='A' && r[i]<='Z')
			printf("%c",s[r[i]-'A']+'A');
		else printf("%c",r[i]);
	}
	printf("\n");
	return 0;
}
