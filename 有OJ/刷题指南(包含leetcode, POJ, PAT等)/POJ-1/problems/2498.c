#include<stdio.h>
int main()
{
	int n,i,j,k,a[3]={9,3,7},t,x,y;
	char s[8];
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		t=0;
		scanf("%s",s);
		for (j=0;s[j]!='\0';j++);
		for (j--,k=0;j>=0;j--)
		{
			if (s[j]=='?')
			{
				x=j;
				y=k++;
			}
			else t+=(s[j]-'0')*a[k++];
			if (k==3)
				k=0;
		}
		t%=10;
		if (t==0)
			s[x]='0';
		else {
			t=10-t;
			while (t%a[y]!=0)
				t+=10;
			s[x]=t/a[y]+'0';
		}
		printf("Scenario #%d:\n%s\n\n",i,s);
	}
	return 0;
}
