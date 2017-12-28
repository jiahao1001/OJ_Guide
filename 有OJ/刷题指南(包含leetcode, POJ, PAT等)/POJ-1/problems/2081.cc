#include<stdio.h>
int main()
{
	int m[500001],i;
	bool n[4000000]={1};
	for(i=1;i<500001;i++)
	{
		if (m[i-1]>i && n[m[i-1]-i]==0)
			m[i]=m[i-1]-i;
		else m[i]=m[i-1]+i;
		n[m[i]]=1;
	}
	scanf("%d",&i);
	while(i!=-1)
	{
		printf("%d\n",m[i]);
		scanf("%d",&i);
	}
	return 0;
}
