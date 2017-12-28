#include<stdio.h>
#include<string.h>
int len;
char str[100];
int left(int j)
{
	int i;
	for (i=j-1;i>=0;i--)
	{
		if (str[i]=='.')
			return 100;
		else if (str[i]=='|' || str[i]=='\\')
			return 0;
	}
	return 100;
}
int right(int j)
{
	int i;
	for (i=j+1;i<len;i++)
	{
		if (str[i]=='.')
			return 100;
		else if (str[i]=='|' || str[i]=='/')
			return 0;
	}
	return 100;
}
int main()
{
	int s,i;
	gets(str);
	while (strcmp(str,"#")!=0)
	{
		len=strlen(str);
		s=0;
		for (i=0;i<len;i++)
		{
			if (str[i]=='.')
				s+=100;
			else if (str[i]=='/')
				s+=left(i);
			else if (str[i]=='\\')
				s+=right(i);
			else if (str[i]=='|')
				s+=(left(i)+right(i))/2;
		}
		printf("%d\n",s/len);
		gets(str);
	}
	return 0;
}
