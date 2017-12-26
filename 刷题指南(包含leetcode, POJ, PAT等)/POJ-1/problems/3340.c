#include <stdio.h>
#include <string.h>
char str[50];
__int64 td;
int len;
int judge(__int64 mid)
{
	int i;
	__int64 sd=0;
	char r[50];
	for (i=len-1;i>=0;i--)
	{
		if (str[i]=='?')
		{
			r[i]=mid%10+'0';
			mid/=10;
		}
		else r[i]=str[i];
	}
	for (i=0;i<len;i++)
	{
		sd*=10;
		sd+=r[i]-'0';
	}
	if (sd>td)
		return 1;
	else if (sd==td)
		return 0;
	else return -1;
}
int main ()
{
	int i;
	__int64 low,high,mid,total;
	while (scanf("%s",str),strcmp(str,"#")!=0)
	{
		len=strlen(str);
		scanf("%I64d",&td);
		low=0;
		high=1;
		for (i=0;i<len;i++)
			if (str[i]=='?')
				high*=10;
		high--;
		total=high;
		if (judge(low)>0)
			total=high+1;
		else if (judge(high)<0)
			total=0;
		else 
		{
			total=high;
			while (low<high-1)
			{
				mid=(low+high)/2;
				i=judge(mid);
				if (i>0)
					high=mid-1;
				else low=mid;
			}
			if (judge(low+1)<=0)
				low++;
			total-=low;
		}
		printf("%I64d\n",total);
	}
	return 0;
}
