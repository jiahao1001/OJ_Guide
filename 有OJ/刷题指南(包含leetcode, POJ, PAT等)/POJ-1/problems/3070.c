#include<stdio.h>
int f[100008];
int main()
{
	long n,i,j;
	int ok=0;
	f[0]=0;
	f[1]=1;
	for (i=2;i<=100000;i++)
	{
		f[i]=(f[i-1]+f[i-2])%10000;
		for (j=0;j<i-1;j++)
		{
			if (f[j]==f[i-1] && f[i]==f[j+1])
			{
				ok=1;
				break;
			}
		}
		if (ok) break;
	}
    while (scanf("%ld",&n),n!=-1)
        printf("%d\n",f[n%15000]);
	return 0;
}
