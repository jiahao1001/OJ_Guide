#include <stdio.h>
int main()
{
	int r,y;
	double m,s;
	scanf("%d %lf %d",&r,&m,&y);
	s=r/100.0+1;
	for (r=0;r<y;r++)
		m*=s;
	printf("%d\n",(int)m);
	return 0;
}
