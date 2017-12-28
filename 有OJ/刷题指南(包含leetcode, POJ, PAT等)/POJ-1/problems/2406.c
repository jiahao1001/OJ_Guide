#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,l;
	char s[1000001];
	scanf("%s",s);
	while (s[0]!='.')
	{
		k=0;
		l=strlen(s);
		for (i=1;i<l;i++)
		{
			if (s[i]==s[0] && l%i==0)
			{
				for (j=i+1;j<l;j++)
					if (s[j]!=s[j-i])
						break;
				if (j==l)
				{
					k=1;
					printf("%d\n",j/i);
					break;
				}
			}
		}
		if (k==0)
			printf("1\n");
		scanf("%s",s);
	}
	return 0;
}
