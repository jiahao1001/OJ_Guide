#include <stdio.h>
int t;
char str[1000];
void space()
{
	while (str[t]==' ')
		t++;
}
void fuhao()
{
	if (str[t]=='+' || str[t]=='-')
		t++;
}
bool zhengshu()
{
	space();
	if (str[t]>='0' && str[t]<='9')
	{
		t++;
		while (str[t]!='\0' && str[t]>='0' && str[t]<='9')
			t++;
		space();
		return true;
	}
	return false;
}
bool point()
{
	if (str[t]=='.')
	{
		t++;
		return zhengshu();
	}
	return true;
}
bool zhishu()
{
	if (str[t]=='E' || str[t]=='e')
	{
		t++;
		fuhao();
		return zhengshu();
	}
	return true;
}
bool real()
{
	int s;
	t=0;
	fuhao();
	if (zhengshu()==true)
	{
		if (point()==false)
			return false;
		if (zhishu()==false)
			return false;
		if (str[t]!='\0')
			return false;
		return true;
	}
	return false;
}
int main()
{
	int i,t;
	scanf("%d\n",&t);
	for (i=0;i<t;i++)
	{
		gets(str);
		if (real()==true)
			printf("LEGAL\n");
		else printf("ILLEGAL\n");
	}
	return 0;
}
