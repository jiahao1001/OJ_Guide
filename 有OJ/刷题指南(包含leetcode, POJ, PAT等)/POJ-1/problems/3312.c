#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n,k;
int len[1000];
int cmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (x<y)
		return -1;
	else if (x>y)
		return 1;
	else return 0;
}
int main()
{
	int test=1,i,j,l,s;
	char str[200];
	while (scanf("%d%d\n",&n,&k),n!=0 || k!=0)
	{
		for (i=0;i<n;i++)
		{
			scanf("%s\n",str);
			len[i]=strlen(str);
		}
		qsort(len,n,sizeof(len[0]),cmp);
		j=n/k;
		printf("Case %d: ",test++);
		for (i=0;i<j;i++)
		{
			for (l=0,s=0;l<k;l++)
				s+=len[i*k+l];
			s/=k;
			for (l=0;l<k;l++)
				if (len[i*k+l]>s+2 || s-2>len[i*k+l])
					break;
			if (l<k)
				break;
		}
		if (i<j)
			printf("no\n\n");
		else printf("yes\n\n");
	}
	return 0;
}
