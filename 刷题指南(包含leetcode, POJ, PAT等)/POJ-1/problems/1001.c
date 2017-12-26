#include <stdio.h>
int main()
{
	int n,point,i,j,k,l,value,w=0,temp;
	char str[150]={0},a[7];
	while (scanf("%s%d",a,&n)!=EOF)
	{
		value=0;
		for (i=0;i<=w;i++)
			str[i]=0;
		for (i=0,j=4;i<=5;i++)
		{
			if (a[i]=='.')
				point=(5-i)*n-1;
			else{
				str[j--]=a[i]-'0';
				value=value*10+a[i]-'0';
			}
		}
		w=4;
		for (i=2;i<=n;i++)
		{
			for (j=w;j>=0;j--)
			{
				temp=str[j]*value;
				k=j;
				str[k++]=temp%10;
				temp/=10;
				while(temp!=0)
				{
					str[k]+=temp%10;
					l=k++;
					while (str[l]>=10)
					{
						str[l+1]+=str[l]/10;
						str[l++]%=10;
					}
					if (l>w)
						w=l;
					temp/=10;
				}
				if (k>w+1)
					w=k-1;
			}
		}
		for (j=0;j<=w;j++)
		{
			if (str[j]!=0)
				break;
		}
		j--;
		if (point>w)
		{
			printf(".");
			for (k=point;k>w;k--)
				printf("0");
		}
		for (i=w;i>=0;i--)
		{
			if (i<=j && i<=point)
				break;
			if (i==point)
				printf(".");
			printf("%d",str[i]);
		}
		printf("\n");
	}
	return 0;
}
