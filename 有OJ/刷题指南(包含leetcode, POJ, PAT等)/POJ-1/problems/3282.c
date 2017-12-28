#include<stdio.h>
#include<string.h>
char str[100];
int left[100000],right[100000];
int n,l,m;
int main()
{
	int i,j,k,sum;
	int car,a,b,L,R;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&l,&m);
		l*=100;
		L=0;
		R=0;
		for (j=0;j<m;j++)
		{
			scanf("%d %s",&car,str);
			if (strcmp(str,"left")==0)
				left[L++]=car;
			else right[R++]=car;
		}
		a=1;
		b=1;
		k=0;
		for (j=0;j<L;j++)
		{
			if (k+left[j]>l)
			{
				a++;
				k=left[j];
			}
			else k+=left[j];
		}
		k=0;
		for (j=0;j<R;j++)
		{
			if (k+right[j]>l)
			{
				b++;
				k=right[j];
			}
			else k+=right[j];
		}
		if (a==b || a==b+1)
			sum=a+b;
		else {
			if (b>a)
				sum=b+b;
			else sum=a+a-1;
		}
		printf("%d\n",sum);
	}
	return 0;
}
