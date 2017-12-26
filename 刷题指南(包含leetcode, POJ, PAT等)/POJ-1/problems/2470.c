#include<stdio.h>
int num[100001];
int main ()
{
	int i,n;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=1;i<=n;i++)
			scanf("%d",&num[i]);
		for (i=1;i<=n;i++)
			if (i!=num[num[i]])
				break;
		if (i>n)
			printf("ambiguous\n");
		else printf("not ambiguous\n");
		scanf("%d",&n);
	}
	return 0;
}
