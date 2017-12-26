#include<stdio.h>
#include<string.h>
int numofword,un,po,ne,unsi[30],posi[30],neti[30],id;
char word[110][25],str[100];
bool flag[110][26];
void search()
{
	int i,j;
	for (i=0;i<numofword;i++)
	{
		for (j=0;j<un;j++)
			if (flag[i][unsi[j]]==true)
				break;
		if (j==un && un!=0)
			continue;
		for (j=0;j<po;j++)
			if (flag[i][posi[j]]==false)
				break;
		if (j<po)
			continue;
		for (j=0;j<ne;j++)
			if (flag[i][neti[j]]==true)
				break;
		if (j<ne)
			continue;
		if (id==-1 || strcmp(word[i],word[id])<0)
			id=i;
	}
}
int main()
{
	int i;
	scanf("%s",word[0]);
	while (strcmp(word[0],"#")!=0)
	{
		numofword=0;
		memset(flag,false,sizeof(flag));
		while (strcmp(word[numofword],"*")!=0)
		{
			for (i=0;word[numofword][i]!='\0';i++)
				flag[numofword][word[numofword][i]-'a']=true;
			scanf("%s",word[++numofword]);
		}
		scanf("%s",str);
		while (strcmp(str,"**")!=0)
		{
			i=0;
			id=-1;
			while (str[i]!='\0')
			{
				for (un=0,po=0,ne=0;str[i]!='\0' && str[i]!='|';i++)
				{
					if (str[i]=='+')
						posi[po++]=str[++i]-'a';
					else if (str[i]=='-')
						neti[ne++]=str[++i]-'a';
					else unsi[un++]=str[i]-'a';
				}
				search();
				if (str[i]=='|')
					i++;
			}
			if (id==-1)
				printf("NONE\n");
			else printf("%s\n",word[id]);
			scanf("%s",str);
		}
		printf("$\n");
		scanf("%s",word[0]);
	}
	return 0;
}
