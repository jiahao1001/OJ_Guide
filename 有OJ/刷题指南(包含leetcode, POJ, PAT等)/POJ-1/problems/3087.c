#include<stdio.h>
#include<string.h>
int n;
char str[250];
void change(char s[],char t[])
{
	int i,j=0;
	for (i=n;i<n+n;i++)
	{
		t[j++]=s[i];
		t[j++]=s[i-n];
	}
	t[n+n]='\0';
}
int main()
{
	int answer,i,t;
	char s[250],s1[250],target[250];
	scanf("%d",&t);
	for (i=1;i<=t;i++)
	{
		answer=0;
		scanf("%d",&n);
		scanf("%s",s);
		scanf("%s",s+n);
		scanf("%s",target);
		strcpy(str,s);
		while(strcmp(target,s)!=0)
		{
			change(s,s1);
			strcpy(s,s1);
			if (strcmp(s,str)==0)
			{
				answer=-1;
				break;
			}
			answer++;
		}
		printf("%d %d\n",i,answer);
	}
	return 0;
}
