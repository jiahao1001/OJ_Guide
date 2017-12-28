#include<stdio.h>
int m,j;
char s[10001];
int cmp(int i,char c,int n);
int cmpd(int i,char c,char h);
int main()
{
	int i,t,x;
	while (gets(s)!=NULL)
	{
		for (i=0,j=0;s[i]!='\0';i++)
			if (s[i]=='i' || s[i]=='v' || s[i]=='x' || s[i]=='l' || s[i]=='c' || s[i]=='d' || s[i]=='m')
				s[j++]=s[i];
		s[j]='\0';
		t=0;
		i=cmp(0,'m',0);
		t+=1000*m;
		i=cmp(i,'d',1);
		t+=500*m;
		i=cmp(i,'c',3);
		t+=100*m;
		i=cmpd(i,'x','c');
		if (m==1)
			t+=90;
		else {
			i=cmp(i,'l',1);
			t+=50*m;
			i=cmp(i,'x',3);
			t+=10*m;
		}
		i=cmpd(i,'i','x');
		if (m==1)
			t+=9;
		else {
			i=cmp(i,'v',1);
			t+=5*m;
			i=cmp(i,'i',3);
			t+=m;
		}
		printf("%d\n",t);
	}
	return 0;
}
int cmp(int i,char c,int n)
{
	int k=i;
	m=0;
	while (i<j)
	{
		if (s[i]==c)
		{
			m++;
			k=i;
			if (m==n)
				return i+1;
		}
		i++;
	}
	return k;
}
int cmpd(int i,char c,char h)
{
	int k=i;
	char p=c;
	m=0;
	while (i<j)
	{
		if (s[i]==p)
		{
			if (m==1)
				return i+1;
			m=1;
			p=h;
		}
		i++;
	}
	m=0;
	return k;
}
