#include<stdio.h>
#include<string.h>
int t[26],r[26];
char s[100];
int main()
{
	int i,j,k,n;
	scanf("%d\n",&n);
	for (i=1;i<=n;i++)
	{
		memset(t,0,sizeof(int)*26);
		memset(r,0,sizeof(int)*26);
		gets(s);
		for (j=0;s[j]!='\0';j++)
			t[s[j]-'a']++;
		gets(s);
		for (j=0;s[j]!='\0';j++)
			r[s[j]-'a']++;
		for (j=0,k=0;j<26;j++)
			k+=(t[j]>r[j]) ? t[j]-r[j] : r[j]-t[j];
		printf("Case #%d:  %d\n",i,k);
	}
	return 0;
}
