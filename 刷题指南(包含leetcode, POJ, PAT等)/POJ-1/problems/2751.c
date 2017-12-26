#include<stdio.h>
int set[2][10000][2],p,q;
void quick(int s,int t,int k);
void swap(int i,int j,int k);
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	while (n!=0)
	{
		for (i=0,p=0,q=0;i<n;i++)
		{
			scanf("%d%d",&j,&k);
			if (j<k)
			{
				set[0][p][0]=j;
				set[0][p][1]=k;
				p++;
			}
			else {
				set[1][q][0]=j;
				set[1][q][1]=k;
				q++;
			}
		}
		quick(0,p-1,0);
		quick(0,q-1,1);
		for (i=0,j=0,k=0;i<p;i++)
		{
			j+=set[0][i][0];
			if (k<j)
				k=j;
			k+=set[0][i][1];
		}
		for (i=q-1;i>=0;i--)
		{
			j+=set[1][i][0];
			if (k<j)
				k=j;
			k+=set[1][i][1];
		}
		printf("%d\n",k);
		scanf("%d",&n);
	}
	return 0;
}
void quick(int s,int t,int k)
{
	int i,j;
	if (s<t)
	{
		i=s;
		j=t+1;
		while (1)
		{
			do{
				i++;
			}while(!(set[k][s][k]<=set[k][i][k] || i==t));
			do{
				j--;
			}while(!(set[k][s][k]>=set[k][j][k] || j==s));
			if (i<j)
				swap(i,j,k);
			else break;
		}
		swap(s,j,k);
		quick(s,j-1,k);
		quick(j+1,t,k);
	}
}
void swap(int i,int j,int k)
{
	int temp;
	temp=set[k][i][0];
	set[k][i][0]=set[k][j][0];
	set[k][j][0]=temp;
	temp=set[k][i][1];
	set[k][i][1]=set[k][j][1];
	set[k][j][1]=temp;
}
