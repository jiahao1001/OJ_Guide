#include<stdio.h>
#include<stdlib.h>
int p[100],m;
int cmp(const void *a,const void *b)
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
int find(int q)
{
	int i=0,j=m-1,k;
	while (i<j)
	{
		k=(i+j)/2;
		if (p[k]==q)
			return 1;
		if (p[k]>q)
			i=k+1;
		else j=k-1;
	}
	if (p[(i+j)/2]==q)
		return 1;
	return 0;
}
int main()
{
	int n,i,j,k,f,a,b,c;
	scanf("%d",&m);
	while (m!=0)
	{
		scanf("%d",&n);
		for (i=0;i<m;i++)
			scanf("%d",&p[i]);
		qsort(p,m,sizeof(p[0]),cmp);
		f=1;
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			for (j=0,k=0;j<a;j++)
			{
				scanf("%d",&c);
				if (f==1 && k<b)
				{
					if (find(c)==1)
						k++;
				}
			}
			if (k<b)
				f=0;
		}
		if (f==1)
			printf("yes\n");
		else printf("no\n");
		scanf("%d",&m);
	}
	return 0;
}
