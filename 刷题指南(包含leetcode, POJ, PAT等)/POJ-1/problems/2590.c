#include<stdio.h>
int main()
{
	int n,i,a,b,s;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		b-=a;
		s=0;
		for (a=0;s<b;a+=2)
			s+=a+2;
		if (s-a/2>=b && s!=0)
			a--;
		printf("%d\n",a);
	}
	return 0;
}
