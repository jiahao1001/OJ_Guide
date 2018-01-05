#include<stdio.h>
// 先整体后细节。
//此题先排版，后输出
int main()
{
	char outPutBuf[82][82];
	char a,b; //待输入的字符
	int n; //叠框大小，奇数
	bool firstcase = true;
	while(scanf("%d %c %c",&n,&a,&b)!=EOF)
	{
		    if(firstcase)
				firstcase = false;
			else
				printf("\n");
		int i,j,k; //用来循环
		for(i=1,j=1;i<=n;i+=2,j++)
		{  //从里往外输出每个圈
			int x = n/2+1;
			int y = x;
			x-=(j-1);
			y-=(j-1);  //计算左上角的坐标
			char c=j%2==1?a:b; //j为奇，则用a
			for(k=1;k<=i;k++)
			{
				outPutBuf[x+k-1][y] = c; //左边
				outPutBuf[x][y+k-1] = c; //上边
				outPutBuf[x+i-1][y+k-1] = c; //下边
				outPutBuf[x+k-1][y+i-1] = c; //右边
			}
		}
		//除了只有一个元素的情况
		if(n!=1)
		{
			outPutBuf[1][1] = ' ';
			outPutBuf[1][n] = ' ';
			outPutBuf[n][1] = ' ';
			outPutBuf[n][n] = ' ';
		}
		for(i=1;i<=n;i++)
		{					
			for(j=1;j<=n;j++)
				printf("%c",outPutBuf[i][j]);
			printf("\n");
		}
	}
	return 0;
}