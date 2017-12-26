#include<stdio.h>
int main()
{
	double l=0,v=0,t1=0,t2;
	char s[9],c;
	while (scanf("%s",s)!=EOF)
	{
		c=getchar();
		t2=(s[0]-'0')*10.0+(s[1]-'0')+((s[3]-'0')*10+(s[4]-'0'))/60.0+((s[6]-'0')*10+(s[7]-'0'))/3600.0;
		l+=v*(t2-t1);
		t1=t2;
		if (c=='\n')
			printf("%s %.2lf km\n",s,l);
		else if (c==' ')
			scanf("%lf",&v);
	}
	return 0;
}
