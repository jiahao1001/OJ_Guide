#include<stdio.h>
#include<math.h>
int main()
{
	int l[21],i,j=1;
	double r=log(2),p=4*r,s=0;
	for (i=0;i<22;i++)
	{
		while(s<p)
			s+=log(j++);
		l[i]=j-2;
		p*=2;
	}
	scanf("%d",&i);
	while (i!=0)
	{
		printf("%d\n",l[(i-1960)/10]);
		scanf("%d",&i);
	}
	return 0;
}
