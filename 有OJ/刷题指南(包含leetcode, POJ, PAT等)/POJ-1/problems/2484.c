#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	while (n!=0)
	{
		if (n>2)
			printf("Bob\n");
		else printf("Alice\n");
		scanf("%d",&n);
	}
	return 0;
}
