#include<stdio.h>
int main()
{
	int i,j,k,l,m,n;
	char s[41],t[41],r[81]={0},c;
	for(k=0;k<41;k++)  
	{
		scanf("%c",&c);
		if(c<'0'|| c>'9')
			break;
		s[k]=c-'0';
	}
	for(l=0;l<41;l++)  
	{
		scanf("%c",&c);
		if(c<'0'||c>'9')
			break;
		t[l]=c-'0';
	}
	for (i=k-1;i>=0;i--)
	{
		m=k-1-i;
		for (j=l-1;j>=0;j--)
		{
			r[m]+=s[i]*t[j];
			n=m;
			while (r[n]>9)
			{
				r[n+1]+=r[n]/10;
				r[n]%=10;
				n++;
			}
			m++;
		}
	}
	for (i=k+l;r[i]==0 && i>0;i--);
	for (j=i;j>=0;j--)
		printf("%d",r[j]);
	printf("\n");
	return 0;
}
