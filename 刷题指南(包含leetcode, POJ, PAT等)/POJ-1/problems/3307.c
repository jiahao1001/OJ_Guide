#include<stdio.h>
__int64 sister[80422]={0,1};
int q=2;
void make()
{
	int a,b,c,d;
	__int64 e,f,g,h;
	a=b=c=d=1;
	while (q<80422)
	{
		e=sister[a]*2;
		f=sister[b]*3;
		g=sister[c]*5;
		h=sister[d]*7;
		if (e<=f && e<=g && e<=h)
		{
			sister[q++]=e;
			a++;
			if (e==f)	b++;
			if (e==g)	c++;
			if (e==h)	d++;
		}
		else if (f<=e && f<=g && f<=h)
		{
			sister[q++]=f;
			b++;
			if (f==e)	a++;
			if (f==g)	c++;
			if (f==h)	d++;
		}
		else if (g<=e && g<=f && g<=h)
		{
			sister[q++]=g;
			c++;
			if (g==e)	a++;
			if (g==f)	b++;
			if (g==h)	d++;
		}
		else {
			sister[q++]=h;
			d++;
			if (h==e)	a++;
			if (h==f)	b++;
			if (h==g)	c++;
		}
	}
}
int main()
{
	int test,i,j;
	make();
	scanf("%d\n",&test);
	for (i=0;i<test;i++)
	{
		scanf("%d",&j);
		printf("%I64d\n",sister[j]);
	}
	return 0;
}
