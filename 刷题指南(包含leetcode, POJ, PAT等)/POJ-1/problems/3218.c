#include <stdio.h>
#include <string.h>
#define LEFT	0
#define RIGHT	1
#define CENTER	2
#define JUSTIFY	3
char line[100]={'\0'};
char str[100];
int len=0;
int makeline()
{
	int l=strlen(str);
	while (l+len<=75)
	{
		strcat(line,str);
		strcat(line," ");
		len=strlen(line);
		if (scanf("%s",str)==EOF)
		{
			len--;
			line[len]='\0';
			return -1;
		}
		l=strlen(str);
	}
	len--;
	line[len]='\0';
	return 1;
}
void left()
{
	printf("%s\n",line);
}
void right()
{
	int i;
	for (i=75-len;i>0;i--)
		putchar(' ');
	printf("%s\n",line);
}
void center()
{
	int i;
	int r=75-len;
	int l=r/2;
	r-=l;
	for (i=0;i<l;i++)
		putchar(' ');
	printf("%s",line);
	for (i=0;i<r;i++)
		putchar(' ');
	putchar('\n');
}
void justify()
{
	int i,l=75-len,sum=0,j;
	for (i=0;i<len;i++)
		if (line[i]==' ')
			sum++;
	if (sum!=0)
	{
		j=l/sum;
		l=l%sum;
	}
	for (i=0;i<len;i++)
	{
		if (line[i]==' ')
		{
			for (sum=0;sum<j;sum++)
				putchar(' ');
			if (l>0)
			{
				putchar(' ');
				l--;
			}
		}
		putchar(line[i]);
	}
	putchar('\n');
}
int main()
{
	int type;
	scanf("%s",str);
	if (str[0]=='L')
		type=LEFT;
	else if (str[0]=='R')
		type=RIGHT;
	else if (str[0]=='C')
		type=CENTER;
	else type=JUSTIFY;
	scanf("%s",str);
	while (makeline()==1)
	{
		if (type==LEFT)
			left();
		else if (type==RIGHT)
			right();
		else if (type==CENTER)
			center();
		else justify();
		len=0;
		line[0]='\0';
	}
	if (type==LEFT)
		left();
	else if (type==RIGHT)
		right();
	else if (type==CENTER)
		center();
	else left();
    return 0;
}
