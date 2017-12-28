#include<iostream>
bool f[1000000]={true,true};
int main()
{
	int i,j,a,d,n;
	for (i=2;i<=1000;i++)
	{
		if (f[i]==true)
			continue;
		for (j=i*i;j<1000000;j+=i)
			f[j]=true;
	}
	scanf("%d%d%d",&a,&d,&n);
	while (a!=0 || d!=0 || n!=0)
	{
		for (i=0,j=a;i<n;j+=d)
			if (f[j]==false)
				i++;
		printf("%d\n",j-d);
		scanf("%d%d%d",&a,&d,&n);
	}
	return 0;
}
