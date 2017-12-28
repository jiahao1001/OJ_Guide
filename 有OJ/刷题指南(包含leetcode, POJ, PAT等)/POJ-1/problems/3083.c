#include<stdio.h>
int w,h;
char map[40][40];
int path[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
void bfs(int a,int b)
{
	int queue[1600][2]={a,b},front=0,rear=1;
	int step[40][40]={0},i,j;
	step[a][b]=1;
	while (front<rear)
	{
		i=queue[front][0];
		j=queue[front][1];
		if (i>0 && map[i-1][j]!='#' && (step[i-1][j]==0 || step[i-1][j]>step[i][j]+1))
		{
			queue[rear][0]=i-1;
			queue[rear][1]=j;
			step[i-1][j]=step[i][j]+1;
			rear++;
		}
		if (i<h-1 && map[i+1][j]!='#' && (step[i+1][j]==0 || step[i+1][j]>step[i][j]+1))
		{
			queue[rear][0]=i+1;
			queue[rear][1]=j;
			step[i+1][j]=step[i][j]+1;
			rear++;
		}
		if (j>0 && map[i][j-1]!='#' && (step[i][j-1]==0 || step[i][j-1]>step[i][j]+1))
		{
			queue[rear][0]=i;
			queue[rear][1]=j-1;
			step[i][j-1]=step[i][j]+1;
			rear++;
		}
		if (j<w-1 && map[i][j+1]!='#' && (step[i][j+1]==0 || step[i][j+1]>step[i][j]+1))
		{
			queue[rear][0]=i;
			queue[rear][1]=j+1;
			step[i][j+1]=step[i][j]+1;
			rear++;
		}
		front++;
	}
	for (i=0;i<h;i++)
	{
		for (j=0;j<w;j++)
			if (map[i][j]=='E')
				break;
		if (j<w)
			break;
	}
	printf("%d\n",step[i][j]);
}
int ok(int a,int b)
{
	if (a<0 || b<0 || a>=h || b>=w) return 0;
	if (map[a][b]=='#') return 0;
	return 1;
}
void left(int j,int k)
{
	int dir,count=1;
	int a,b,bf=1;
	while (map[j][k]!='E')
	{
		dir=(bf+3)%4;
		do{
			a=j+path[dir][0];
			b=k+path[dir][1];
			dir=(dir+1)%4;
		}while (!ok(a,b));
		j=a;
		k=b;
		bf=(dir+3)%4;
		count++;
	}
	printf("%d ",count);
}
void right(int j,int k)
{
	int dir,count=1;
	int a,b,bf=1;
	while (map[j][k]!='E')
	{
		dir=(bf+1)%4;
		do{
			a=j+path[dir][0];
			b=k+path[dir][1];
			dir=(dir+3)%4;
		}while (!ok(a,b));
		j=a;
		k=b;
		bf=(dir+1)%4;
		count++;
	}
	printf("%d ",count);
}
int main()
{
	int i,j,k,t;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d%d",&w,&h);
		for (j=0;j<h;j++)
			scanf("%s",map[j]);
		for (j=0;j<h;j++)
		{
			for (k=0;k<w;k++)
				if (map[j][k]=='S')
					break;
			if (k<w)
				break;
		}
		left(j,k);
		right(j,k);
		bfs(j,k);	
	}
	return 0;
}
