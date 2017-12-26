#include<stdio.h>
#include<string.h>
int breed[10001]={0},n,k;
int main()
{
	int i,j=1,p,s;
	scanf("%d%d",&n,&k);
	for (i=0,s=0;i<n;i++)
	{
		scanf("%d",&p);
		if (breed[p]==0)
		{
			s++;
			breed[p]=1;
			if (s==k)
			{
				s=0;
				j++;
				memset(breed,0,sizeof(int)*k+1);
			}
		}
	}
	printf("%d\n",j);
	return 0;
}
