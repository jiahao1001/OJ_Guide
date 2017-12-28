#include <stdio.h>
int main()
{
	int n,i,b,c,t,h,r[9];
	char s[9][9];
	scanf("%d",&n);
	while (n!=-1)
	{
		t=0;
		h=0;
		for (i=0;i<n;i++)
		{
			scanf("%d %d %d %s",&r[i],&b,&c,s[i]);
			r[i]*=b*c;
			if (r[i]>r[t])
				t=i;
			else if (r[i]<r[h])
				h=i;
		}
		printf("%s took clay from %s.\n",s[t],s[h]);
		scanf("%d",&n);
	}
	return 0;
}
