#include<stdio.h>
#define MAX 1000000000
int min,m[300],t[300],wise[2][301];
void dp(int i,int j,int time,int fine,int flag,int re);
int main()
{
	int i,n;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=0;i<n;i++)
			scanf("%d%d",&m[i],&t[i]);
		wise[0][0]=0;
		for (i=1;i<=n;i++)
			wise[0][i]=wise[0][i-1]+t[i-1];
		wise[1][n]=0;
		for (i=n-1;i>=0;i--)
			wise[1][i]=wise[1][i+1]+t[i];
		min=MAX;
		dp(1,n-1,0,0,0,0);
		printf("%d\n",min);
		scanf("%d",&n);
	}
	return 0;
}
void dp(int i,int j,int time,int fine,int flag,int re)
{
	int p;
	if (fine>=min)
		return;
	if (i>j)
	{
		min=fine;
		return;
	}
	if (flag==0)
	{
		p=time+t[i-1];
		dp(i+1,j,p,fine+p*m[i],0,re);
		if (re<2)
		{
			p=time+wise[0][i-1]+wise[1][j];
			dp(i,j-1,p,fine+p*m[j],1,re+1);
		}
	}
	else{
		p=time+t[j];
		dp(i,j-1,p,fine+p*m[j],1,re);
		if (re<2)
		{
			p=time+wise[1][j+1]+wise[0][i];
			dp(i+1,j,p,fine+p*m[i],0,re+1);
		}
	}
}
