#include<stdio.h>
int a,b,c,d,e,f,g,h,I;
int fun[1001];
int mod(int a,int b)
{
	int c=a%b;
	if (c<0)
		c+=b;
	return c;
}
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&I);
		fun[0]=a;
		fun[1]=b;
		fun[2]=c;
		for (j=3;j<=I;j++)
		{
			if (j%2==1)
				fun[j]=mod(d*fun[j-1]+e*fun[j-2]-f*fun[j-3],g);
			else fun[j]=mod(f*fun[j-1]-d*fun[j-2]+e*fun[j-3],h);
		}
		printf("%d\n",fun[I]);
	}
	return 0;
}
