#include<stdio.h>
#include<string.h>
int i,j,k,n,m,l;
bool p[26],check[26];
char s[500];
int main()
{
	while(scanf("%d",&n),n)
	{
		memset(p,0,sizeof(p));
		memset(check,0,sizeof(check));
		scanf("%s",s);
		m=0;
		k=strlen(s);
		for (i=0;i<k;i++)
		{
			l=s[i]-'A';
			if (p[l])
			{
				p[l]=0;
				if (!check[l])
					n++;
				else m++;
			}
			else 
			{
				p[l]=1;
				if (n) 
					n--;
				else check[l]=1;
			}
		}
		if (m) 
			printf("%d customer(s) walked away.\n",m);
		else printf("All customers tanned successfully.\n");
	}
	return 0;
}
