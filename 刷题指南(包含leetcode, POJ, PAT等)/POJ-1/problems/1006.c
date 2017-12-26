#include <stdio.h>
int main()
{
	int m,p,e,i,d,j=1;
	while (1)
	{
		scanf("%d %d %d %d",&p,&e,&i,&d);
		if (p==-1 && e==-1 && i==-1 && d==-1)
			break;
		m=(5544*(p%23)+14421*(e%28)+1288*(i%33))%21252-d;
		if (m<=0)
			m+=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",j,m);
		j++;
	}
	return 0;
}
