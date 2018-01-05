/*
	在一个整型数组a中既有负数又有正数,编写一个算法
将a中所有负数移到正数之前,要求其时间复杂度为O(n),n
为数组长度,并且只使用常数个辅助空间.
*/
#include <stdio.h>

//二分法划分正负数(时间复杂度O(n), 空间复杂度O(1))
void DivideIntegers(int num[], int n)
{
	int l=0, r=n-1;
	int temp;

	while(l<r)
	{
		//得到当前左边第一个正数下标
		while(num[l] < 0) l++;

		//得到当前右边第一个负数下标
		while(num[r] > 0) r--;

		////由于正负数都有, 所以可以忽略这种情况
		//if(l==n || r==-1)//全负或全正
		//{
		//	break;
		//}

		//交换
		temp = num[l];
		num[l] = num[r];
		num[r] = temp;

		l++;
		r--;
	}
}

int main()
{
	int num[] = {1, 2, 3, 4, -1, 1, -2, -1, -4};
	int n=9, i;

	//输出划分前的结果
	for(i=0; i<n; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");

	//划分
	DivideIntegers(num, n);

	//输出划分后的结果
	for(i=0; i<n; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	return 0;
}