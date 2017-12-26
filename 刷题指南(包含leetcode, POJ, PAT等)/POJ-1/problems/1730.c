#include<stdio.h>
#include<math.h>
#define zero 1e-6
int powb(__int64 t,__int64 x)
{
	int b=2,p=1,a=1,i;
	if (2==t%4)
		return 1;
	if (t%5==2 || t%5==3 || x<0)
		a=2;
	for (i=a+1;b>1;i+=a)
	{
		b=(int)(pow(t,1.0/i)+zero);
		if(fabs(pow(b,i)-t)<zero)
			p=i;
	}
	return p;
}
int main()
{
	__int64 x;
	while(scanf("%I64d",&x),x)
		printf("%d\n",powb(x>0?x:-x,x));
	return 0;
}
