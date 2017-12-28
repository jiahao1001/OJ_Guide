#include<stdio.h>
int n,d[4];
int main()
{
	int i,j,k,p,t,big,small;
	while (scanf("%d",&n),n!=-1)
	{
		printf("N=%d:\n",n);
		if (n<1000 || n>9999 || n==1111 || n==2222 || n==3333 || n==4444 || n==5555 || n==6666 || n==7777 || n==8888 || n==9999)
		{
			printf("No!!\n");
			continue;
		}
		t=0;
		while (n!=6174 && n!=0)
		{
			d[0]=d[1]=d[2]=d[3]=0;
			for (p=0,j=n;j>0;p++,j/=10)
				d[p]=j%10;
			for (i=0;i<p;i++)
			{
				for (j=i+1;j<p;j++)
				{
					if (d[i]<d[j])
					{
						k=d[i];
						d[i]=d[j];
						d[j]=k;
					}
				}
			}
			for (big=0,i=0;i<p;i++)
				big=big*10+d[i];
			for (i=p-1;d[i]==0 && i>=0;i--);
			for (small=0;i>=0;i--)
				small=small*10+d[i];
			n=big-small;
			t++;
			printf("%d-%d=%d\n",big,small,n);
		}
		printf("Ok!! %d times\n",t);
	}
	return 0;
}
