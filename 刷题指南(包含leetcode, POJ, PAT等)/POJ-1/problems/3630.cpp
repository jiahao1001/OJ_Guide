#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sequence[10000];
char phone[10000][20];
int cmp(const void *a,const void *b)
{
	int x=*(int *)a;
	int y=*(int *)b;
	if (strcmp(phone[x],phone[y])<0)
		return -1;
	else if (strcmp(phone[x],phone[y])>0)
		return 1;
	else return 0;
}
int main()
{
	int i,j;
	int t,n;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d\n",&n);
		for (j=0;j<n;j++)
		{
			gets(phone[j]);
			sequence[j]=j;
		}
		qsort(sequence,n,sizeof(sequence[0]),cmp);
		for (j=1;j<n;j++)
		{
			if (strncmp(phone[sequence[j-1]],phone[sequence[j]],strlen(phone[sequence[j-1]]))==0)
				break;
		}
		if (j<n)
			printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
