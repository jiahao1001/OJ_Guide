#include<iostream>
#include<cstring>
using namespace std;
struct Shot{
	int x;
	int y;
	bool be;
	int degree;
}shot[1000];
struct Command{
	int time;
	int name;
	int content;
	int angle;
}command[1000];
int qshot,n;
void shotmove();
class Tank
{
public:
	Tank(int lx,int ly,int ldegree);
	Tank();
	~Tank();
	void settank(int lx,int ly,int ldegree);
	void bemoving();
	void stop();
	void turn(int d);
	void moving();
	void shooting();
	void killing();
	void bomb();
	bool getbe();
private:
	int x;
	int y;
	int degree;
	bool move;
	bool be;
};
Tank tank[10];
int main()
{
	int m,i,j,x,y,degree,qcommand,time,c,d;
	char name[10][11],strna[11],strco[6];
	scanf("%d%d",&n,&m);
	while (n!=0 || m!=0)
	{
		c=0;
		for (i=0;i<n;i++)
		{
			scanf("%s%d%d%d",name[i],&x,&y,&degree);
			x*=6;
			y*=6;
			tank[i].settank(x,y,degree);
		}
		for (i=0;i<m;i++)
		{
			scanf("%d%s%s",&command[i].time,strna,strco);
			command[i].time*=6;
			for (j=0;j<n;j++)
				if (strcmp(strna,name[j])==0)
					break;
			command[i].name=j;
			if (strcmp(strco,"MOVE")==0)
				command[i].content=1;
			else if (strcmp(strco,"STOP")==0)
				command[i].content=0;
			else if (strcmp(strco,"TURN")==0)
			{
				scanf("%d",&command[i].angle);
				command[i].content=2;
			}
			else if (strcmp(strco,"SHOOT")==0)
				command[i].content=3;
		}
		qshot=0;
		qcommand=0;
		for (time=0;time<=258;time++)
		{
			while (qcommand<m && command[qcommand].time==time)
			{
				if (command[qcommand].content==1)
					tank[command[qcommand].name].bemoving();
				else if (command[qcommand].content==0)
					tank[command[qcommand].name].stop();
				else if (command[qcommand].content==2)
					tank[command[qcommand].name].turn(command[qcommand].angle);
				else if (command[qcommand].content==3)
					tank[command[qcommand].name].shooting();
				qcommand++;
			}
			for (i=0;i<n;i++)
				tank[i].moving();
			shotmove();
			for (i=0;i<n;i++)
				tank[i].killing();
		}
		for (i=0;i<n;i++)
		{
			if (tank[i].getbe()==true)
			{
				d=i;
				c++;
			}
		}
		if (c==0 || c>1)
			printf("NO WINNER!\n");
		else printf("%s\n",name[d]);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
Tank::Tank(int lx,int ly,int ldegree)
{
	x=lx;
	y=ly;
	degree=ldegree;
	move=false;
	be=true;
}
Tank::Tank()
{
	x=0;
	y=0;
	degree=0;
	move=false;
	be=false;
}
Tank::~Tank()
{
}
void Tank::settank(int lx,int ly,int ldegree)
{
	x=lx;
	y=ly;
	degree=ldegree;
	move=false;
	be=true;
}
void Tank::bemoving()
{
	if (be==true)
		move=true;
}
void Tank::stop()
{
	if (be==true)
		move=false;
}
void Tank::turn(int d)
{
	if (be==true)
		degree=(degree+d+360)%360;
}
void Tank::moving()
{
	if (be==true && move==true)
	{
		if (degree==0)
		{
			if (x==720)
				move=false;
			else x+=10;
		}
		else if (degree==90)
		{
			if (y==720)
				move=false;
			else y+=10;
		}
		else if (degree==180)
		{
			if (x==0)
				move=false;
			else x-=10;
		}
		else {
			if (y==0)
				move=false;
			else y-=10;
		}
	}
}
void Tank::shooting()
{
	if (be==true)
	{
		shot[qshot].x=x;
		shot[qshot].y=y;
		shot[qshot].degree=degree;
		shot[qshot].be=true;
		qshot++;
	}
}
bool Tank::getbe()
{
	return be;
}
void Tank::killing()
{
	int i;
	if (be==false)
		return;
	for (i=0;i<qshot;i++)
	{
		if (shot[i].be==false)
			continue;
		if (shot[i].x==x && shot[i].y==y)
		{
			shot[i].be=false;
			be=false;
		}
	}
}
void shotmove()
{
	int i;
	for (i=0;i<qshot;i++)
	{
		if (shot[i].be==true)
		{
			if (shot[i].degree==0)
			{
				if (shot[i].x>700)
					shot[i].be=false;
				else shot[i].x+=20;
			}
			else if (shot[i].degree==90)
			{
				if (shot[i].y>700)
					shot[i].be=false;
				else shot[i].y+=20;
			}
			else if (shot[i].degree==180)
			{
				if (shot[i].x<20)
					shot[i].be=false;
				else shot[i].x-=20;
			}
			else {
				if (shot[i].y<20)
					shot[i].be=false;
				else shot[i].y-=20;
			}
		}
	}
}
