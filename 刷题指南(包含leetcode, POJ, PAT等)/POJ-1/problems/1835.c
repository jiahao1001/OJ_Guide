#include<stdio.h>
#include<string.h>
int Head,Nova,x,y,z;
int Direct[6][3]={{1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1}};
int Left[6][6]={{-1,2,4,-1,5,1},{5,-1,0,2,-1,3},{1,3,-1,4,0,-1},{-1,5,1,-1,2,4},{2,-1,3,5,-1,0},{4,0,-1,1,3,-1}};
int reverse(int i);
void forward(int foot);
void back(int foot);
void left(int foot);
void right(int foot);
void up(int foot);
void down(int foot);
int main()
{
	int test,t,i,n,foot;
	char str[100];
	scanf("%d",&test);
	for (t=0;t<test;t++)
	{
		Nova=0;
		Head=2;
		x=0;
		y=0;
		z=0;
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%s",str);
			scanf("%d",&foot);
			if (strcmp(str,"forward")==0)
				forward(foot);
			else if (strcmp(str,"back")==0)
				back(foot);
			else if (strcmp(str,"left")==0)
				left(foot);
			else if (strcmp(str,"right")==0)
				right(foot);
			else if (strcmp(str,"up")==0)
				up(foot);
			else if (strcmp(str,"down")==0)
				down(foot);
		}
		printf("%d %d %d %d\n",x,y,z,Nova);
	}
	return 0;
}
int reverse(int i)
{
	return (i+3)%6;
}
void forward(int foot)
{
	x+=Direct[Nova][0]*foot;
	y+=Direct[Nova][1]*foot;
	z+=Direct[Nova][2]*foot;
}
void back(int foot)
{
	Nova=reverse(Nova);
	forward(foot);
}
void left(int foot)
{
	Nova=Left[Nova][Head];
	forward(foot);
}
void right(int foot)
{
	Nova=reverse(Left[Nova][Head]);
	forward(foot);
}
void up(int foot)
{
	int temp=Head;
	Head=reverse(Nova);
	Nova=temp;
	forward(foot);
}
void down(int foot)
{
	int temp=Nova;
	Nova=reverse(Head);
	Head=temp;
	forward(foot);
}
