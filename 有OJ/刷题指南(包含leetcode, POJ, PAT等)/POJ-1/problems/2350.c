#include <stdio.h>
int main()
{
	int n,m,i,j,t,r;
	char s[1000];
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d",&m);
		t=0;
		for (j=0;j<m;j++)
		{
			scanf("%d",&s[j]);
			t+=s[j];
		}
		t/=m;
		r=0;
		for (j=0;j<m;j++)
			if (s[j]>t)
				r++;
		printf("%.3lf%c\n",100.0*r/m,'%');
	}
	return 0;
}
