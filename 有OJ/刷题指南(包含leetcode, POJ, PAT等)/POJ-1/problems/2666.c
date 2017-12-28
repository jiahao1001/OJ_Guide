#include <stdio.h>
#include<math.h>
#define PI 3.141592653589793
int main()
{
	int Speed,Angle,Dis;
	double Conver,X,Y;
	while(scanf("%d%d%d",&Speed,&Angle,&Dis))
	{    
		if(Speed==0)
			break;
		Conver=(double)Angle;
		Conver*=PI/180;
		Conver/=1.732050808;
		X=log((double)Dis);
		Y=X+Conver;
		X=exp(Y)-Dis;
		X/=Speed;
		if (X<=10000)
			printf("%d\n",(int)(0.5+X));
		else printf("God help me!\n");
	}
	return 0;
}
