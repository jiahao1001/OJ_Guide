#include<stdio.h>
#include<string.h>
int n;
char word[10000][26],query[26];
int cmp()
{
	int j;
	for (j=0;j<n;j++)
	{
		if (strcmp(word[j],query)==0)
		{
			printf("%s is correct\n",query);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int m,i,j,l,x,y,z,len;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%s",word[i]);
	scanf("%d",&m);
	for (i=0;i<m;i++)
	{
		scanf("%s",query);
		if (cmp()==1)
			continue;
		len=strlen(query);
		for (j=0;j<n;j++)
		{
			z=strlen(word[j]);
			if (z-len>1 || len-z>1)
				continue;
			for (l=0;word[j][l]==query[l];l++);
			if (z==len)
			{
				if (word[j][l+1]==query[l+1])
					l++;
				else if (word[j][l]==query[l+1] && word[j][l+1]==query[l])
					l+=2;
				for (;l<z;l++)
					if (word[j][l]!=query[l])
						break;
				if (l==z)
				{
					printf("%s is a misspelling of %s\n",query,word[j]);
					break;
				}
			}
			else {
				if (len==z+1)
				{
					x=l;
					y=l+1;
				}
				else
				{
					x=l+1;
					y=l;
				}
				while (x<z)
				{
					if (word[j][x]!=query[y])
						break;
					x++;
					y++;
				}
				if (x==z)
				{
					printf("%s is a misspelling of %s\n",query,word[j]);
					break;
				}
			}
		}
		if (j==n)
			printf("%s is unknown\n",query);
	}
	return 0;
}
