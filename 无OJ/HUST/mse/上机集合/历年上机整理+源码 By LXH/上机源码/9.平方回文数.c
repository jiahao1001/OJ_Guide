/*
	写程序给出100以上至1000以内的平方回文数
例如:121, 既是完全平方数, 也是回文数
*/
#include <stdio.h>
#include <math.h>

//是否是完全平方数
int IsSquare(int num)
{
	int sqr = (int)(sqrt(num*1.0));

	return (sqr*sqr == num ||
		(sqr+1)*(sqr+1) == num);
}

//是否是回文数(3位)
int IsReverse(int num)
{
	return num%10 == 
		num/100;
}

int main()
{
	int i;

	for(i=100; i<1000; i++)
	{
		if(IsSquare(i) &&
			IsReverse(i))
		{
			printf("%d\n", i);
		}
	}
	
	return 0;
}