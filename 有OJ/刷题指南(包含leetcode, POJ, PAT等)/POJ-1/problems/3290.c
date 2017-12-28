#include<stdio.h>
#include<string.h>
char str[200];
char pqrst[200],KACE[200];
int len,Len,N;
void Middle(int p)
{
	if (N>0 && str[p]>='a' && str[p]<='z')
	{
		while (N>0)
		{
			putchar('N');
			N--;
		}
	}
	putchar(str[p]);
	if (p+p+1<len)
		Middle(p+p+1);
	if (p+p+2<len)
		Middle(p+p+2);
}
int main()
{
	int i,j;
	while (scanf("%s",str),strcmp(str,"0")!=0)
	{
		len=0;
		Len=0;
		N=0;
		for (i=0;str[i]!='\0';i++)
		{
			if (str[i]=='p' || str[i]=='q' || str[i]=='r' || str[i]=='s' || str[i]=='t')
				pqrst[len++]=str[i];
			else if (str[i]=='N')
				N++;
			else if (str[i]=='K' || str[i]=='A' || str[i]=='C' || str[i]=='E')
				KACE[Len++]=str[i];
		}
		if (len==0)
			printf("no WFF possible\n");
		else {
			if (len>Len)
				len=Len+1;
			else Len=len-1;
			for (i=0;i<Len;i++)
				str[i]=KACE[i];
			for (j=0;j<len;i++,j++)
				str[i]=pqrst[j];
			len+=Len;
			str[len]='\0';
			Middle(0);
			putchar('\n');
		}
	}
	return 0;
}
