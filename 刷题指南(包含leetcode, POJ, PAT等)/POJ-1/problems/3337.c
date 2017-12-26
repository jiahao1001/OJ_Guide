#include <stdio.h>
#include <string.h>
char str[1000];
int letter[26],flag[26];
int ch,sym;
int lexer()
{
	if (str[ch]=='\0')
		return -1;
	while (str[ch]==' ')
		ch++;
	if (str[ch]>='a' && str[ch]<='z')
	{
		flag[str[ch]-'a']=1;
		return str[ch++]-'a';
	}
	if (str[ch]=='+')
	{
		ch++;
		if (str[ch]=='+')
		{
			ch++;
			return 26;//++
		}
		else return 28;//+
	}
	if (str[ch]=='-')
	{
		ch++;
		if (str[ch]=='-')
		{
			ch++;
			return 27;//--
		}
		else return 29;//-
	}
	return -1;
}
int factor()
{
	int p,q;
	if (sym==26)
	{
		p=lexer();
		letter[p]++;
		sym=lexer();
		return letter[p];
	}
	if (sym==27)
	{
		p=lexer();
		letter[p]--;
		sym=lexer();
		return letter[p];
	}
	if (sym>=0 && sym<26)
	{
		p=sym;
		q=letter[p];
		sym=lexer();
		if (sym==26)
		{
			sym=lexer();
			letter[p]++;
		}
		else if (sym==27)
		{
			sym=lexer();
			letter[p]--;
		}
		return q;
	}
}
int expression()
{
	int lvalue,rvalue,id;
	lvalue=factor();
	while (sym>=0)
	{
		id=sym;
		sym=lexer();
		rvalue=factor();
		if (id==28)
			lvalue+=rvalue;
		else if (id==29)
			lvalue-=rvalue;
	}
	return lvalue;
}
int main ()
{
	int t,i,j;
	scanf("%d\n",&t);
	for (i=0;i<t;i++)
	{
		gets(str);
		j=0;
		while (j<26)
		{
			flag[j]=0;
			letter[j]=j+1;
			j++;
		}
		ch=0;
		printf("Expression: %s\n",str);
		sym=lexer();
		printf("value = %d\n",expression());
		for (j=0;j<26;j++)
		{
			if (flag[j]==1)
				printf("%c = %d\n",j+'a',letter[j]);
		}
	}
	return 0;
}
