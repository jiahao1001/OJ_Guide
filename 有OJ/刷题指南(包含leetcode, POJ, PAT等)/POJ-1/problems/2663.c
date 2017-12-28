#include <stdio.h>
int tri(int n)
{
	int sum=1,i,temp=3;
	if (n==1)
		return 3;
	for(i=1;i<n;i++)
	{
		sum=sum+temp;
		temp=3*temp+2*(sum-temp);
	}
	return temp;
}
int main()
{
	int input;
	scanf("%d",&input);
	while(input!=-1)
	{
		if(input%2==1)
			printf("0\n");
		else if (input==0)
			printf("1\n");
		else printf("%d\n",tri(input/2));
		scanf("%d",&input);
	}
	return 0;
}
