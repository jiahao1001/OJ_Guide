/*
	编程解决"八皇后问题":即在一个8*8的矩形格子中排放8个
皇后,要满足的条件包括:任意两个皇后都不能在同一行/列/对角
线(斜率等于1/-1).
	要求编程给出所有第一行第一列有皇后的解
(注：解的输出用8个数字表示,如：基本解{1,5,8,6,3,7,2,4},其
中'1'表示第一行第一列即(1,1)处有皇后, 后同)
*/
#include <stdio.h>

#define N 8

//棋子
typedef struct c
{
	int i;
	int j;
}Chessman;

//棋盘
typedef struct ca
{
	int			len;
	Chessman	chess[N];
}QueenArr;

//八皇后棋盘
QueenArr queenArr = {0};
//解
int result[N];

//初始化
void Init()
{
	//摆好第一颗固定的棋子
	queenArr.len = 1;
	queenArr.chess[0].i = 0;
	queenArr.chess[0].j = 0;

	result[0] = 0;
}

//输出解
void Output()
{
	int i;

	printf("{");

	for(i=0; i<N; i++)
	{
		printf("%d,", result[i]+1);
	}
	
	printf("%d}\n", result[i]+1);
}

//检验是否满足条件(不同行/列/对角线)
int Check()
{
	int		j;//循环变量
	float	k;//斜率
	int		isOk = 1;//标记是否满足条件
	int		i = queenArr.len - 1;//新添加棋子的下标
	Chessman *arr = queenArr.chess;//棋盘

	for(j=0; j<i; j++)
	{
		//求斜率
		k = 1.0f * (arr[i].i - arr[j].i) / 
			(arr[i].j - arr[j].j);

		if( arr[i].i == arr[j].i ||//同行
			arr[i].j == arr[j].j ||//同列
			k == 1 || k == -1 )//同对角线
		{
			isOk = 0;
			break;
		}
	}

	return isOk;
}

/*
 *求解(回溯算法)
 *@i: 当前遍历棋盘的行标
 */
void Solution(int i)
{
	//摆好所有的棋子,直接输出解
	if(i == N)
	{
		Output();
	}
	else
	{
		int j;
		for(j=1; j<N; j++)
		{
			//摆棋子
			queenArr.chess[queenArr.len].i = i;
			queenArr.chess[queenArr.len].j = j;
			queenArr.len++;

			//满足条件
			if(Check())
			{
				result[i] = j;//记录结果集

				Solution(i+1);//试探下一行
			}

			//回溯
			queenArr.len--;
		}
	}
}

int main()
{
	Init();

	Solution(1);

	return 0;
}