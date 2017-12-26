#include<stdio.h>
int main()
{
	int d[10]={0},c=0,a=0,i,j,s,p;
	char t[1001];
	scanf("%s",t);
	for (i=0;t[i]!='\0';i++)
		d[t[i]-'0']++;
	if (d[0]==0 && d[5]==0)
		printf("impossible");
	else
	{
		s=d[1]+2*d[2]+3*d[3]+4*d[4]+5*d[5]+6*d[6]+7*d[7]+8*d[8]+9*d[9];
		p=s%3;
		if (d[0]==0)
			c=1;
		if (p==1)
		{
			for (i=1;i<9;i+=3)
			{
				if (d[i]>0)
				{
					d[i]--;
					break;
				}
			}
			if (i>9)
			{
				if (d[2]>1)
					d[2]-=2;
				else if (d[2]>0)
				{
					d[2]--;
					if (d[5]>c)
						d[5]--;
					else if (d[8]>0)
						d[8]--;
					else a=1;
				}
				else if (d[5]>c+1)
					d[5]-=2;
				else if (d[5]>c)
				{
					d[5]--;
					if (d[8]>0)
						d[8]--;
					else a=1;
				}
				else if (d[8]>1)
					d[8]-=2;
				else a=1;
			}
		}
		else if (p==2)
		{
			if (d[2]>0)
				d[2]--;
			else if (d[5]>c)
				d[5]--;
			else if (d[8]>0)
				d[8]--;
			else{
				for (i=1,j=2;j>0 && i<9;i+=3)
				{
					while (d[i]>0)
					{
						d[i]--;
						j--;
						if (j==0)
							break;
					}
				}
				if (j>0)
					a=1;
			}
		}
		if (a==1)
			printf("impossible");
		else if (d[1]+d[2]+d[3]+d[4]+d[5]+d[6]+d[7]+d[8]+d[9]==0)
			printf("0");
		else {
			d[5]-=c;
			for (i=9;i>=0;i--)
			{
				for (j=d[i];j>0;j--)
					printf("%d",i);
			}
			if (c==1)
				printf("5");
		}
	}
	printf("\n");		
	return 0;
}
