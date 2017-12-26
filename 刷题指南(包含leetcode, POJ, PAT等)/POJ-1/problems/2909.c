#include<stdio.h>
int main()
{
	int i,j,k,n,q=1,r,m,s;
	short p[3504]={3};
	for (i=5;i<32679;i+=2)
	{
		for (j=0;j<q;j++)
			if (i%p[j]==0)
				break;
		if (j==q)
			p[q++]=i;
	}
	scanf("%d",&n);
	while (n!=0)
	{
		r=0;
		if (n==4)
			printf("1\n");
		else{
			for (i=0;p[i]*2<=n;i++)
			{
				s=n-p[i];
				for (k=i,j=q-1;k<=j;)
				{
					m=(k+j)/2;
					if (p[m]<s)
						k=m+1;
					else if (p[m]>s)
						j=m-1;
					else {
						r++;
						break;
					}
				}
			}
			printf("%d\n",r);
		}
		scanf("%d",&n);
	}
	return 0;
}
