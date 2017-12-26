#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sequence[10];
char phone[10][20];
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
	int j;
	int t=1,n;
	while (gets(phone[0])!=NULL)
	{
		n=0;
		while (strcmp(phone[n],"9")!=0)
		{
			sequence[n]=n;
			n++;
			gets(phone[n]);
		}
		qsort(sequence,n,sizeof(sequence[0]),cmp);
		for (j=1;j<n;j++)
		{
			if (strncmp(phone[sequence[j-1]],phone[sequence[j]],strlen(phone[sequence[j-1]]))==0)
				break;
		}
		if (j==n)
			printf("Set %d is immediately decodable\n",t);
		else printf("Set %d is not immediately decodable\n",t);
		t++;
	}
	return 0;
}
