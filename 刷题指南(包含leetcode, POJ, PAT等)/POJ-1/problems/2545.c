#include<stdio.h>
int main()
{
	__int64 f[3000]={1};
	int i=0,j=0,k=0,p,q,r,s=1,n;
	scanf("%d%d%d%d",&p,&q,&r,&n);
	while (s<=n)
	{
		if (f[i]*p<=f[j]*q && f[i]*p<=f[k]*r)
		{
			if (f[i]*p==f[s-1])
				i++;
			else f[s++]=f[i++]*p;
		}
		if (f[j]*q<=f[i]*p && f[j]*q<=f[k]*r)
		{
			if (f[j]*q==f[s-1])
				j++;
			else f[s++]=f[j++]*q;
		}
		if (f[k]*r<=f[i]*p && f[k]*r<=f[j]*q)
		{
			if (f[k]*r==f[s-1])
				k++;
			else f[s++]=f[k++]*r;
		}
	}
	printf("%I64d\n",f[n]);
	return 0;
}
