#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,f[11]={0};
	char s[20];
	scanf("%d",&n);
	while (n!=0)
	{
		getchar();
		gets(s);
		if (strcmp(s,"too high")==0)
		{
			for (i=n;i<11;i++)
				f[i]=1;
		}
		else if (strcmp(s,"too low")==0)
		{
			for (i=1;i<=n;i++)
				f[i]=1;
		}
		else{
			if (f[n]==0)
				printf("Stan may be honest\n");
			else printf("Stan is dishonest\n");
			for (i=1;i<11;i++)
				f[i]=0;
		}
		scanf("%d",&n);
	}
	return 0;
}
