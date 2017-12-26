#include<stdio.h>
#include<string.h>
int main()
{
	int b,i,j,k,s[105]={0};
	char t[105];
	scanf("%s",t);
	while (t[0]!='0' || t[1]!='\0')
	{
		b=strlen(t);
		j=0;
		for (i=b-1;i>=0;i--)
		{
			s[j]+=t[i]-'0';
			k=j;
			while (s[k]>9)
			{
				s[k++]-=10;
				s[k]++;
			}
			j++;
		}
		scanf("%s",t);
	}
	for (i=104;i>0 && s[i]==0;i--);
	while (i>=0)
		printf("%d",s[i--]);
	printf("\n");
	return 0;
}
