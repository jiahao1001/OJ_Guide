#include<stdio.h>
#include<stdlib.h>
bool pqrst[5];
int w;
char WFF[200];
bool dfs()
{
	bool a,b;
	char ch=WFF[w++];
	if (ch=='K' || ch=='A' || ch=='C' || ch=='E')
	{
		a=dfs();
		b=dfs();
		if (ch=='K')
			return a && b;
		if (ch=='A')
			return a || b;
		if (ch=='C')
		{
			if (a==true && b==false)
				return false;
			else return true;
		}
		if (ch=='E')
		{
			if (a==b)
				return true;
			else return false;
		}
	}
	else if (ch=='N')
	{
		a=dfs();
		return !a;
	}
	else if (ch=='p')
		return pqrst[4];
	else if (ch=='q')
		return pqrst[3];
	else if (ch=='r')
		return pqrst[2];
	else if (ch=='s')
		return pqrst[1];
	else if (ch=='t')
		return pqrst[0];
	return false;
}
void simple(int bin)
{
	int i;
	for (i=0;i<5;i++)
	{
		if (bin%2==0)
			pqrst[i]=false;
		else pqrst[i]=true;
		bin=bin>>1;
	}
}
int main()
{
	int i;
	while (scanf("%s",WFF),WFF[0]!='0')
	{
		for (i=0;i<32;i++)
		{
			w=0;
			simple(i);
			if (dfs()==false)
				break;
		}
		if (i<32)
			printf("not\n");
		else printf("tautology\n");
	}
	return 0;
}
