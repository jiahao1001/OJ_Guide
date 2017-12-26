#include<stdio.h>
#include<string.h>
char str[100];
int main()
{
	int i,j,k,l,len;
	gets(str);
	while (strcmp(str,"*")!=0)
	{
		len=strlen(str);
		for (i=0;i<len;i++)
		{
			for (j=i+1;j<len;j++)
			{
				if (str[i]==str[j])
				{
					l=j-i;
					for (k=i+1;k+l<len;k++)
						if (str[k]==str[k+l])
							break;
					if (k+l<len)
						break;
				}
			}
			if (j<len)
				break;
		}
		if (i<len)
			printf("%s is NOT surprising.\n",str);
		else printf("%s is surprising.\n",str);
		gets(str);
	}
	return 0;
}
