/*
	一群人(排列序号从1到N,N可设定)围成一圈,
按一定规则出列,剩余的人仍然围成一圈.出列规则
是顺着1到N的方向对圈内的人从1到C计数(C可设定),
圈内计数为C的人出列,剩余的人重新计数,按上述规
则,让圈内所有的人出列.请编程顺序输出出列编号的
序列
*/
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//约瑟夫环
void Josephus(int n, int c)
{
	int *flag;//标记数组
	int out, report, index;//出列人数, 报数, 当前报数者下标

	//初始化
	flag = (int*)malloc(sizeof(int)*n);
	memset(flag, 0, sizeof(int)*n);

	out = 0;
	index = -1;

	//循环
	while(out<n)
	{
		//新一轮报数初始化0
		report=0;

		//报数
		while(report < c)
		{
			index = (index+1)%n;

			if(!flag[index])
			{
				report++;
			}
		}

		//出列
		flag[index] = 1;
		out++;
		printf("%d\n", index+1);
	}

	free(flag);
}

int main()
{
	int N, C;

	printf("N = ");
	scanf("%d", &N);

	printf("C = ");
	scanf("%d", &C);

	Josephus(N, C);

	return 0;
}