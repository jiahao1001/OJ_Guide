#include<stdio.h>
#define ISYEAP(x) ((x%4==0&&x%100!=0)||(x%400==0))?1:0

//编程顺序，应该先编写day，调试；
//然后编写month，year等等，要一步步来

int dayOfMonth[13][2] = 
{//后者是闰年
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
}; //这个";"一定要加上
struct Date
{
	int year;
	int month;
	int day;
	void nextDay()
	{
		day++;
		if(day>dayOfMonth[month][ISYEAP(year)])
		{
			day = 1;
			month++;
			if(month>12)
			{				
				month = 1;
				year++;
			}
		}
	}
};
int buf[5001][13][32];
int Abs(int x)
{
	return x<0?-x:x;
}
int main()
{
	Date tmp;
	int cnt = 0; //只是用来计数的，然后存在buf中
	tmp.year = 0;  //把0年1月1日作为基准
	tmp.month = 1;	
	tmp.day = 1;
	while(tmp.year!=5001)
	{
		buf[tmp.year][tmp.month][tmp.day] = cnt;
		tmp.nextDay();
		cnt++;

	}
	int y1,m1,d1;
	int y2,m2,d2;
	while(scanf("%4d%2d%2d",&y1,&m1,&d1)!=EOF)
	{
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		printf("%d\n",Abs(buf[y2][m2][d2]-buf[y1][m1][d1])+1);
	}
	return 0;
}