#include<stdio.h>
int main()
{
	int i;
	double d[8];
	while (scanf("%lf",&d[0])!=EOF)
	{
		for (i=1;i<8;i++)
			scanf("%lf",&d[i]);
		if (d[4]==d[2] && d[5]==d[3])
		{
			d[4]=(d[0]+d[6])/2;
			d[5]=(d[1]+d[7])/2;
			d[2]=d[4]+d[4]-d[2];
			d[3]=d[5]+d[5]-d[3];
			printf("%.3lf %.3lf\n",d[2],d[3]);
		}
		else if (d[4]==d[0] && d[5]==d[1])
		{
			d[4]=(d[2]+d[6])/2;
			d[5]=(d[3]+d[7])/2;
			d[0]=d[4]+d[4]-d[0];
			d[1]=d[5]+d[5]-d[1];
			printf("%.3lf %.3lf\n",d[0],d[1]);
		}
		else if (d[6]==d[0] && d[7]==d[1])
		{
			d[6]=(d[2]+d[4])/2;
			d[7]=(d[3]+d[5])/2;
			d[0]=d[6]+d[6]-d[0];
			d[1]=d[7]+d[7]-d[1];
			printf("%.3lf %.3lf\n",d[0],d[1]);
		}
		else{
			d[6]=(d[0]+d[4])/2;
			d[7]=(d[1]+d[5])/2;
			d[2]=d[6]+d[6]-d[2];
			d[3]=d[7]+d[7]-d[3];
			printf("%.3lf %.3lf\n",d[2],d[3]);
		}
	}
	return 0;
}
