#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=705;
int row,col,c;
int map[N][N],_min[N],_max[N];//min/max:第i行[a,b]区间最大/小值
int Q1[N*2],Q2[N*2],f1,f2,r1,r2;
void push1(int k)
{
	while(f1<=r1&&_min[Q1[r1]]>_min[k])
		r1--;
	Q1[++r1]=k;
}
void push2(int k)
{
	while(f2<=r2&&_max[Q2[r2]]<_max[k])
		r2--;
	Q2[++r2]=k;
}
int main()
{
	while(scanf("%d%d%d",&col,&row,&c)!=EOF)
	{
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				scanf("%d",&map[i][j]);
		int ans=0;
		for(int i=0;i<col;i++)
		{
			for(int j=0;j<row;j++)
			_min[j]=_max[j]=map[j][i];
			for(int j=i+1;j<col&&j-i<100;j++)
			{
				for(int k=0;k<row;k++)
				{
					_min[k]=min(_min[k],map[k][j]);
					_max[k]=max(_max[k],map[k][j]);
				}
				f1=f2=0;
				r1=r2=-1;
				int w=j-i+1;
				for(int r=0,f=0;r<row&&(row-f)*w>ans;r++)
				{
					push1(r);
					push2(r);
					while(f<=r&&f1<=r1&&f2<=r2&&_max[Q2[f2]]-_min[Q1[f1]]>c)
					{
						f++;
						while(f2<=r2&&Q2[f2]<f)
						f2++;
						while(f1<=r1&&Q1[f1]<f)
						f1++;
					}
					ans=max(ans,w*(r-f+1));
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
