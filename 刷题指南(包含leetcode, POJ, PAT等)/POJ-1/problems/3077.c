#include<stdio.h>
#include<string.h>
int main()
{
	int t,u,i,j,len;
	char s[100];
	char tmp;
	scanf("%d",&t);
	for (u=0;u<t;u++)
	{
		scanf("%s",s);
		len=strlen(s);
		for (i=0,j=len-1;i<=j;i++,j--)
		{
			tmp=s[i];
			s[i]=s[j];
            s[j]=tmp;
		}
		for (i=0;i<len-1;i++)
		{
			if (s[i]>'4') 
				s[i+1]++;
			s[i]='0';
		}
		if (s[len-1]=='9'+1) 
			printf("10");
		else putchar(s[len-1]);
		for (i=len-2;i>=0;i--) 
			putchar (s[i]);
		putchar ('\n');
	}
	return 0;
}
