/*
	打印出所有的"水仙花数",所谓"水仙花数"
是指一个3位数,其各位数字立方和等于该数本身.
*/
#include <stdio.h>

//是否是水仙花数
int IsPerfectNum(int num)
{
	int sum=0;
	int n = num;
	int digit;

	while(n)
	{
		digit = n%10;
		sum += digit * digit *digit;

		n /= 10;
	}

	return num == sum;
}

int main()
{
	int i;

	for(i=100; i<1000; i++)
	{
		if(IsPerfectNum(i))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}