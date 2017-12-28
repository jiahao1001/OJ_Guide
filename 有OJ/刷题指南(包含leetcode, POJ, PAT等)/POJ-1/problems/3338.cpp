#include<stdio.h>
#include<string.h>
int w,h,s;
bool cake[20][20],wide[20][21],height[21][20];
void rec(int a,int b,int c,int d)
{
	int temp,i,j;
	if (a>c)
	{
		temp=a;
		a=c;
		c=temp;
	}
	if (b>d)
	{
		temp=b;
		b=d;
		d=temp;
	}
	for (i=b;i<d;i++)
	{
		wide[i][a]=true;
		wide[i][c]=true;
	}
	for (i=a;i<c;i++)
	{
		height[b][i]=true;
		height[d][i]=true;
	}
}
void DFS(int i,int j)
{
	cake[i][j]=true;
	if (wide[i][j+1]==false && cake[i][j+1]==false)
		DFS(i,j+1);
	if (wide[i][j]==false && cake[i][j-1]==false)
		DFS(i,j-1);
	if (height[i+1][j]==false && cake[i+1][j]==false)
		DFS(i+1,j);
	if (height[i][j]==false && cake[i-1][j]==false)
		DFS(i-1,j);
}
int main()
{
	int i,j,n;
	int a,b,c,d;
	while (scanf("%d%d",&w,&h),w!=0 || h!=0)
	{
		memset(cake,false,sizeof(cake));
		memset(wide,false,sizeof(wide));
		memset(height,false,sizeof(height));
		s=0;
		scanf("%d",&n);
		rec(0,0,h,w);
		for (i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			rec(a,b,c,d);
		}
		for (i=0;i<w;i++)
		{
			for (j=0;j<h;j++)
			{
				if (cake[i][j]==false)
				{
					DFS(i,j);
					s++;
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
