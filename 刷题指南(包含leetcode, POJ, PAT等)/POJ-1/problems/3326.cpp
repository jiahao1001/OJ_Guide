#include<stdio.h>
#include<string.h>
int n,m,r,q;
int student[10001];
int time[10001];
bool PC[721][10001];
bool used[1001];
int main()
{
	int i,j,a,b,c,d;
	while (scanf("%d%d",&n,&m),n!=0 || m!=0)
	{
		memset(student,0,sizeof(student));
		memset(PC,false,sizeof(PC));
		memset(used,false,sizeof(used));
		scanf("%d",&r);
		for (i=0;i<r;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			a-=540;
			if (d==1 && used[b]==false)
			{
				used[b]=true;
				student[c]++;
				if (student[c]==1)
					time[c]=a;
			}
			else if (d==0 && used[b]==true)
			{
				used[b]=false;
				student[c]--;
				if (student[c]==0)
				{
					for (j=time[c];j<a;j++)
						PC[j][c]=true;
				}
			}
		}
		scanf("%d",&q);
		for (i=0;i<q;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			d=0;
			b-=540;
			for (j=a-540;j<b;j++)
				if (PC[j][c]==true)
					d++;
			printf("%d\n",d);
		}
	}
	return 0;
}
