#include<stdio.h>
int leap(int year)
{
	if (year%4==0 && (year%100!=0 || year%400==0)) return 1;
	return 0;
}
int main()
{
	int year,month,day,num;
	int Month[12]={0,31,28,31,30,31,30,31,31,30,31,30};
	int Leap[12]={0,31,29,31,30,31,30,31,31,30,31,30};
	char Weak[7][15]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
	char dm[32][3]={"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
	scanf("%d",&num);
	while (num!=-1)
	{
		day=num%7;
		for (year=2000;num>=365+leap(year);year++)
			num-=(365+leap(year));
		num++;
		if (leap(year))
		{
			for (month=1;month<12;month++)
			{
				if (num>Leap[month])
					num-=Leap[month];
				else break;
			}
		}
		else {
			for (month=1;month<12;month++)
			{
				if (num>Month[month])
					num-=Month[month];
					else break;
			}
		}
		printf("%d-%s-%s %s\n",year,dm[month],dm[num],Weak[day]);
		scanf("%d",&num);
	}
	return 0;
}
