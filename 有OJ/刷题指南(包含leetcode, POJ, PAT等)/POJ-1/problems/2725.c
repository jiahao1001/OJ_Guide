#include<stdio.h>
#include<math.h>
#include<string.h>
#define A 16807
#define M 2147483647
#define Q 127773
#define R 2836
long seed=1;
double x[2][26],y[2][26];
int random();
void first(int a,int b,int c,int n);
void second(int a,int b,int c,int n);
void third(int a,int b,int c,int n);
int main()
{
	int i,j,k;
	char str[20];
	gets(str);
	while (strcmp(str,"END")!=0)
	{
		do{
			i=str[0]-'A';
			if (str[1]!='\0')
			{
				x[0][i]=0;
				y[0][i]=0;
				for (j=2;str[j]!=' ';j++)
					x[0][i]=x[0][i]*10+str[j]-'0';
				for (j++;str[j]!='\0';j++)
					y[0][i]=y[0][i]*10+str[j]-'0';
				x[1][i]=x[0][i];
				y[1][i]=y[0][i];
			}
			else{
				x[0][i]=random();
				y[0][i]=random();
				x[1][i]=random();
				y[1][i]=random();
			}
			gets(str);
		}while(str[0]>='A' && str[0]<='Z');
		do{
			i=str[2]-'A';
			j=str[4]-'A';
			k=str[6]-'A';
			if (str[0]=='1')
			{
				first(i,j,k,0);
				first(i,j,k,1);
			}
			else if (str[0]=='2')
			{
				second(i,j,k,0);
				second(i,j,k,1);
			}
			else if (str[0]=='3')
			{
				third(i,j,k,0);
				third(i,j,k,1);
			}
			gets(str);
		}while(str[0]>'0' && str[0]<'4');
		i=str[0]-'A';
		if (fabs(x[0][i]-x[1][i])<0.0000001 && fabs(y[0][i]-y[1][i])<0.0000001)
			printf("%.2lf %.2lf\n",x[0][i],y[0][i]);
		else printf("UNCERTAIN!\n");
		gets(str);
	}
	return 0;
}
void first(int a,int b,int c,int n)
{
	x[n][c]=(x[n][a]+x[n][b])/2;
	y[n][c]=(y[n][a]+y[n][b])/2;
}
void second(int a,int b,int c,int n)
{
	double d,l,p,q;
	if (x[n][a]==x[n][b])
	{
		y[n][c]=y[n][b];
		x[n][c]=y[n][a]-y[n][b]+x[n][b];
	}
	else {
		p=x[n][b]-x[n][a];
		q=y[n][b]-y[n][a];
		d=atan2(q,p);
		l=sqrt(p*p+q*q);
		x[n][c]=x[n][b]-sin(d)*l;
		y[n][c]=y[n][b]+cos(d)*l;
	}
}
void third(int a,int b,int c,int n)
{
	double d,l,p,q;
	if (x[n][a]==x[n][b])
	{
		y[n][c]=y[n][b];
		x[n][c]=y[n][b]-y[n][a]+x[n][b];
	}
	else {
		p=x[n][b]-x[n][a];
		q=y[n][b]-y[n][a];
		d=atan2(q,p);
		l=sqrt(p*p+q*q);
		x[n][c]=x[n][b]+sin(d)*l;
		y[n][c]=y[n][b]-cos(d)*l;
	}
}
int random()
{
	double tp;
	long temp;
	temp=A*(seed%Q)-R*(seed/Q);
	if (temp>=0)
		seed=temp;
	else seed=temp+M;
	tp=100.0*seed/M;
	return (int)tp;
}
