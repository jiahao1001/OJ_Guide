#include<stdio.h>
#include<string.h>
int L,N;
char irregularWord[20][2][30];
int main()
{
	int i,j;
	char word[30];
	scanf("%d%d",&L,&N);
	for (i=0;i<L;i++)
		scanf("%s%s",irregularWord[i][0],irregularWord[i][1]);
	for (i=0;i<N;i++)
	{
		scanf("%s",word);
		for (j=0;j<L;j++)
			if (strcmp(word,irregularWord[j][0])==0)
				break;
		if (j<L)
		{
			printf("%s\n",irregularWord[j][1]);
			continue;
		}
		for (j=0;word[j+1]!='\0';j++)
			putchar(word[j]);
		if (word[j]=='y' && word[j-1]!='a' && word[j-1]!='e' && word[j-1]!='i' && word[j-1]!='o' && word[j-1]!='u')
			printf("ies\n");
		else if (word[j]=='o' || word[j]=='s' || word[j]=='x' || (word[j]=='h' && (word[j-1]=='c' || word[j-1]=='s')))
			printf("%ces\n",word[j]);
		else printf("%cs\n",word[j]);
	}
	return 0;
}
