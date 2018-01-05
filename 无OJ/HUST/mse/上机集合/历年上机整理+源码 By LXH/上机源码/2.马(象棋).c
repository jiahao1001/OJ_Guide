/*
	在半个中国象棋棋盘上,马在左下角(1，1)处,马走日字...
而且只能往右走...不能向左...可上可下...求从起点到(m, n)
处有几种不同的走法
*/
#include <stdio.h>

//棋盘的宽度和高度(半个)
#define W 9
#define H 5

#define LOW -1//下界

//棋盘(标记当前点是否被访问过)
static int chess[H][W];

//标记路径的条数
static int count;

//置零
void ClearState()
{
	int i, j;

	for(i=0; i<H; ++i)
	{
		for(j=0; j<W; ++j)
		{
			chess[i][j] = 0;
		}
	}

	count = 0;
}

//是否可以通过
int IsPass(int i, int j)
{
	return (
		(i>LOW && i<H) &&
		(j>LOW && j<W) &&
		!chess[i][j]);
}

//搜索路径(回溯算法)
void Path(int i, int j, int m, int n)
{
	//保证坐标未出界且未被访问
	if(IsPass(i, j))
	{
		//到达目标点
		if(i == m-1 && j == n-1)
		{
			count++;
			return;
		}

		//未达到目标点, 继续搜索

		//标记当前点已被访问
		chess[i][j] = 1;

		Path(i-1, j+2, m, n);//水平右上
		Path(i+1, j+2, m, n);//水平右下
		Path(i-2, j+1, m, n);//垂直右上
		Path(i+2, j+1, m, n);//垂直右下

		//标记当前点未被访问(其它方向的也需要遍历)
		chess[i][j] = 0;
	}
}

int main()
{
	int m, n;

	while(1){
		printf("m n : ");
		scanf("%d %d", &m, &n);
		Path(0, 0, m, n);
		printf("共有%d种走法\n\n", count);

		ClearState();
	}
	
	return 0;
}