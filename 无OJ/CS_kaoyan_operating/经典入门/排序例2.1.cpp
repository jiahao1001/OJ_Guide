#include<stdio.h>
int main()
{
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&buf[i]);		
		//冒泡法排序
		for(int j=0;j<n;j++)
			for(int k=0;k<n-j-1;k++)
				if(buf[k]>buf[k+1])
				{//大的在后
					int tmp = buf[k];
					buf[k] = buf[k+1];
					buf[k+1] = tmp;
				}
		for(i=0;i<n;i++)
			printf("%d ",buf[i]);
		printf("\n");
	}

	/*另：
	char a[4] ="abc";
	char *p;
	p = &a[0];
    printf("%c\n%s\n",*p,p);
	//*p为p指向的第一个字符，
	//而p指向字符串，和%s一起使用*/

	return 0;	
}