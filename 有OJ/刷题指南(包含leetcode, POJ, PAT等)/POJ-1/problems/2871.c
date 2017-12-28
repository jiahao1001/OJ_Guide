#include<stdio.h>
int main()
{
	double t1,t2;
	scanf("%lf%lf",&t1,&t2);
	while (t2-999>0.0000001 || t2-999<-0.0000001)
	{
		printf("%.2lf\n",t2-t1);
		t1=t2;
		scanf("%lf",&t2);
	}
	printf("End of Output\n");
	return 0;
}
