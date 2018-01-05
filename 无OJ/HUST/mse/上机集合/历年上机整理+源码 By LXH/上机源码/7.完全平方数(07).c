/*
	按要求输出：在三位整数(100至999)中寻找符合条件的
整数并依次从小到大存入数组中;他既是完全平方数,又是两
位数字相同,例如144,676等
*/
#include <stdio.h>
#include <math.h>

//是否是完全平方数
int IsSquare(int num)
{
	int sqr = (int)(sqrt(num * 1.0));

	return (sqr*sqr == num ||
		(sqr+1)*(sqr+1) == num );
}

//是否有两位数相同
int IsTwoSame(int num)
{
	int digit0, digit1, digit2;

	digit0 = num%10;
	digit1 = (num/10)%10;
	digit2 = (num/100)%10;

	return (digit0==digit1 || digit0==digit2 || digit1==digit2);
}

int main()
{
	int i;

	for(i=100; i<1000; i++)
	{
		if(IsSquare(i) && IsTwoSame(i))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}