#include<iostream>
bool field[100][100]={false};
int x,y;
void inrange(int i,int j,int r);
void notinrange(int i,int j,int r);
int main()
{
	int i,j,k,t,r,f,s;
    scanf("%d%d%d",&x,&y,&t);
	for (k=0;k<t;k++)
	{
		scanf("%d%d%d%d",&i,&j,&r,&f);
		if (f==0)
			notinrange(i-1,j-1,r);
		else inrange(i-1,j-1,r);
	}
	for (i=0,s=0;i<x;i++)
		for (j=0;j<y;j++)
			if (field[i][j]==false)
				s++;
	printf("%d\n",s);
	return 0;
}
void inrange(int i,int j,int r)
{
	int p=r/2,l,k;
	int a=i-p,b=i+p+1,c=j-p,d=j+p+1;
	if (a<0)
		a=0;
	if (c<0)
		c=0;
	if (b>x)
		b=x;
	if (d>y)
		d=y;
	for (l=0;l<a;l++)
		for (k=0;k<y;k++)
			field[l][k]=true;
	for (l=b;l<x;l++)
		for (k=0;k<y;k++)
			field[l][k]=true;
	for (k=0;k<c;k++)
		for (l=0;l<x;l++)
			field[l][k]=true;
	for (k=d;k<y;k++)
		for (l=0;l<x;l++)
			field[l][k]=true;
}
void notinrange(int i,int j,int r)
{
	int p=r/2,l,k;
	int a=i-p,b=i+p+1,c=j-p,d=j+p+1;
	if (a<0)
		a=0;
	if (c<0)
		c=0;
	if (b>x)
		b=x;
	if (d>y)
		d=y;
	for (l=a;l<b;l++)
		for (k=c;k<d;k++)
			field[l][k]=true;
}
