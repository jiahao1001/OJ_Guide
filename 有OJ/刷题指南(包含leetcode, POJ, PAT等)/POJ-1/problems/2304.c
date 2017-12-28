#include <stdio.h>
int main()
{
	int s,p1,p2,p3,res;
	while(scanf("%d%d%d%d",&s,&p1,&p2,&p3),s!=0 || p1!=0 || p2!=0 || p3!=0)
	{
		res=0;
		if (s<p1)
			res+=40;
		res+=s-p1;
		if (p1>p2)
			res+=40;
		res+=p2-p1;
		if (p2<p3)
			res+=40;
		res+=p2-p3;
		printf("%d\n",res*9+1080);
	}
	return 0;
}
