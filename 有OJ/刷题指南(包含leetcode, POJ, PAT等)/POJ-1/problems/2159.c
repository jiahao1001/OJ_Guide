#include<stdio.h>
#include<stdlib.h>
int s[26]={0},t[26]={0};
int cmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (x<y)
		return -1;
	else if (x>y)
		return 1;
	else return 0;
}
int main()
{
	int i;
	char str[120];
	scanf("%s",str);
	for (i=0;str[i]!='\0';i++)
		s[str[i]-'A']++;
	scanf("%s",str);
	for (i=0;str[i]!='\0';i++)
		t[str[i]-'A']++;
	qsort(s,26,sizeof(s[0]),cmp);
	qsort(t,26,sizeof(s[0]),cmp);
	for (i=0;i<26;i++)
		if (s[i]!=t[i])
			break;
	if (i==26)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}
