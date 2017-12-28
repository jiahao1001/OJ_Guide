#include <stdio.h>
int main()
{
    int n,i,j=1;
	char s[15][26];
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%s",s[i]);
		printf("SET %d\n",j++);
		for (i=0;i<n;i+=2)
			printf("%s\n",s[i]);
		for (i=n-1-n%2;i>0;i-=2)
			printf("%s\n",s[i]);
		scanf("%d",&n);
	}
	return 0;
}
