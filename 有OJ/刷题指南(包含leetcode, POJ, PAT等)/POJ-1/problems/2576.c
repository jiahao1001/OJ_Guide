#include <stdio.h>
#include <stdlib.h>
int a[100],b[100],na,nb,n,sa=0,sb=0;
int cmp(const void *a, const void *b);
int Ab(int x,int y);
int main()
{
	int t[100],i,j,p,q,s;
	scanf("%d",&n);
	na=n/2;
	nb=n-na;
	for (i=0;i<n;i++)
		scanf("%d",&t[i]);
	qsort(t,n,sizeof(t[0]),cmp);
	for (i=0;i<n-1;i+=2)
	{
		a[i/2]=t[i];
		sa+=t[i];
		b[i/2]=t[i+1];
		sb+=t[i+1];
	}
	if (n%2==1)
	{
		b[na]=t[n-1];
		sb+=t[n-1];
	}
	s=Ab(sa,sb);
	for (i=0;i<100000;i++)
	{
		p=rand()%na;
		q=rand()%nb;
		j=Ab(sa-a[p]+b[q],sb-b[q]+a[p]);
		if (j<s)
		{
			s=j;
			sa=sa-a[p]+b[q];
			sb=sb-b[q]+a[p];
			j=a[p];
			a[p]=b[q];
			b[q]=j;
		}
		if (s==0)
			break;
	}
	if (sa>sb)
	{
		j=sb;
		sb=sa;
		sa=j;
	}
	printf("%d %d\n",sa,sb);
    return 0;
}
int cmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (x<y)
		return 1;
	else if (x>y)
		return -1;
	else return 0;
}
int Ab(int x,int y)
{
	if (x>y)
		return x-y;
	else return y-x;
}
