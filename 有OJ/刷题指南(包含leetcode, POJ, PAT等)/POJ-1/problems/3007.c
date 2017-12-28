#include<stdio.h>
#include<string.h>
int len,num;
char str[500][73],s1[72],s2[72],t[73],r[73];
void reversal(char *s,int l)
{
	int i;
	char c;
	for (i=0;i+i<l-1;i++)
	{
		c=s[i];
		s[i]=s[l-1-i];
		s[l-1-i]=c;
	}
}
void store(char *s,char *t,int l)
{
	int i;
	for (i=0;i<l;i++)
		r[i]=s[i];
	for (;i<len;i++)
		r[i]=t[i-l];
	r[i]='\0';
	for (i=0;i<num;i++)
		if (strcmp(r,str[i])==0)
			break;
	if (i==num)
		strcpy(str[num++],r);
}
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%s",t);
		strcpy(str[0],t);
		num=1;
		len=strlen(t);
		for (j=1;j<len;j++)
		{
			for (k=0;k<j;k++)
				s1[k]=t[k];
			s1[k]='\0';
			while (k<len)
			{
				s2[k-j]=t[k];
				k++;
			}
			s2[k-j]='\0';
			store(s2,s1,k-j);
			reversal(s1,j);
			store(s1,s2,j);
			store(s2,s1,k-j);
			reversal(s2,k-j);
			store(s1,s2,j);
			store(s2,s1,k-j);
			reversal(s1,j);
			store(s1,s2,j);
			store(s2,s1,k-j);
		}
		printf("%d\n",num);
	}
	return 0;
}
