#include<stdio.h>
#include<string.h>
int main()
{
	int n,m,i,j,k,a,b;
	char s[100],t[100],r[200];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%s %s",s,t);
		memset(r,0,200);
		for (j=0;s[j]=='0';j++);
		for (k=j;s[k]!='\0';k++);
		for (k--;k>=j && s[k]=='0';k--);
		for (a=0;k>=j;j++)
			r[a++]+=s[j]-'0';
		for (j=0;t[j]=='0';j++);
		for (k=j;t[k]!='\0';k++);
		for (k--;k>=j && t[k]=='0';k--);
		for (a=0;k>=j;j++)
		{
			r[a]+=t[j]-'0';
			b=a++;
			while (r[b]>9)
			{
				r[b++]-=10;
				r[b]++;
			}
		}
		for (j=199;r[j]==0;j--);
		for (k=0;r[k]==0;k++);
		for (;k<=j;k++)
			printf("%d",r[k]);
		printf("\n");
	}
	return 0;
}
