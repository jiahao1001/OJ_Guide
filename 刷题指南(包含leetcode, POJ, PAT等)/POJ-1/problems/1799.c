#include<stdio.h>
#include<math.h>
#define pi  3.14159265358
void main()
{
	int n,i,num;
	double r=0.0,t=0.0,R;	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lf%d",&R,&num);
		t=sin(pi/num);
		r=R*t/(t+1.0);		
		printf("Scenario #%d:\n%.3f\n\n",i,r);		
	}
	return 0;
}
