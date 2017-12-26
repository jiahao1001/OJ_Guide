#include<stdio.h>
#define MAX 1000000000000000
__int64 high,low;
__int64 a,b,c;
int alpha[26],n;
void permutation(int n,int m)
{
	int i;
	a=0;
	b=1;
	for (i=n;i>n-m;i--)
	{
		b*=i;
		a*=i;
		a+=b/MAX;
		b%=MAX;
	}
}
int list(int p)
{
	int i,j=0;
	for (i=0;i<p;i++)
	{
		if (alpha[i]==0)
			j++;
	}
	return j;
}
int main()
{
	int i,j;
	char str[50];
	while (scanf("%d",&n),n!=0)
	{
		scanf("%s",str);
		high=0;
		low=0;
		for (i=0;i<26;i++)
			alpha[i]=0;
		for (i=0;i<n;i++)
		{
			j=str[i]-'A';
			permutation(25-i,n-1-i);
			alpha[j]=1;
			j=list(j);
			b*=j;
			a*=j;
			a+=b/MAX;
			b%=MAX;
			low+=b;
			high+=a;
			high+=low/MAX;
			low%=MAX;
		}
		if (high!=0)
			printf("%I64d%15I64d\n",high,low);
		else printf("%I64d\n",low);
	}
	return 0;
}
