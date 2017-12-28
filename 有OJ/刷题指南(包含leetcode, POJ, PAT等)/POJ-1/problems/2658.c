#include<stdio.h>
#include<string.h>
char syllable[4][60];
int rhyme()
{
	if (strcmp(syllable[0],syllable[1])==0)
	{
		if (strcmp(syllable[0],syllable[2])==0 && strcmp(syllable[0],syllable[3])==0)
			return 0;
		else if (strcmp(syllable[2],syllable[3])==0)
			return 1;
		else return 4;
	}
	if (strcmp(syllable[0],syllable[2])==0)
	{
		if (strcmp(syllable[1],syllable[3])==0)
			return 2;
		else return 4;
	}
	if (strcmp(syllable[0],syllable[3])==0)
	{
		if (strcmp(syllable[1],syllable[2])==0)
			return 3;
		else return 4;
	}
	return 4;
}
int main()
{
	int n,i,j,k,a;
	char str[100],result[5][8]={"perfect","even","cross","shell","free"};
	scanf("%d\n",&n);
	for (i=0;i<n;i++)
	{
		for (j=0;j<4;j++)
		{
			gets(str);
			for (k=0,a=0;str[k]!='\0';k++)
				if (str[k]==' ')
					a=k+1;
			for (k=a;str[k]!='\0';k++)
			{
				if (str[k]>='A' && str[k]<='Z')
					str[k]=str[k]-'A'+'a';
				if (str[k]=='a' || str[k]=='e' || str[k]=='i' || str[k]=='o' || str[k]=='u')
					a=k;
			}
			for (k=a,a=0;str[k]!='\0';k++)
				syllable[j][a++]=str[k];
			syllable[j][a]='\0';
		}
		printf("%s\n",result[rhyme()]);
	}
	return 0;
}
