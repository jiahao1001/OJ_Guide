#include <stdio.h>
#include <string.h>
int coin[12];
int balance(char *s,char *t,char *r)
{
	int left=0,right=0;
	int i,j;
	for (i=0;s[i]!='\0';i++)
		left+=coin[s[i]-'A'];
	for (i=0;t[i]!='\0';i++)
		right+=coin[t[i]-'A'];
	if (strcmp(r,"even")==0 && left==right)
		return 1;
	if (strcmp(r,"up")==0 && left>right)
		return 1;
	if (strcmp(r,"down")==0 && left<right)
		return 1;
	return 0;
}
int main()
{
	int test;
	int i,j,k,l;
	char s[3][10],t[3][10],r[3][10];
	scanf("%d",&test);
	for (i=0;i<test;i++)
	{
		for (j=0;j<3;j++)
			scanf("%s%s%s",s[j],t[j],r[j]);
		for (j=-1;j<=1;j+=2)
		{
			for (k=0;k<12;k++)
			{
				memset(coin,0,sizeof(coin));
				coin[k]=j;
				for (l=0;l<3;l++)
					if (balance(s[l],t[l],r[l])==0)
						break;
				if (l==3)
					break;
			}
			if (k<12)
				break;
		}
		printf("%c is the counterfeit coin and it is ",'A'+k);
		if (j==-1)
			printf("light.\n");
		else printf("heavy.\n");
	}
	return 0;
}
