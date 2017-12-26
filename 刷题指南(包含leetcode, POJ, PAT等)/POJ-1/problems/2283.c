#include<stdio.h>
int x[2][65536]={0},q[131072]={0},p[131072]={0};
int bfs(int a,int b,int n,int t)
{
	int fr=0,r=1,i=0;
	char f[65536]={0};
	q[0]=0;
	if (a==0)
	{
		fr=2;
		q[2]=b;
		r=3;
		f[0]=1;
		p[2]=0;
	}
	while(fr<r)
	{
		if (f[q[fr]]==1)
		{
			fr++;
			continue;
		}
		f[q[fr]]=1;
		q[r]=(q[fr]*10+a)%n;
		p[r]=fr;
		if (q[r]==0)
			break;
		r++;
		q[r]=(q[fr]*10+b)%n;
		p[r]=fr++;
		if (q[r]==0)
			break;
		r++;
	}
	if (fr<r)
	{
		for (i=0;r!=0;i++)
		{
			if (r%2==1)
				x[t][i]=a;
			else x[t][i]=b;
			r=p[r];
		}
		return i-1;
	}
	return -1;
}
int main()
{
	int n,d[10],c,i,j,k,m,t;
	scanf("%d",&n);
	while (n!=0)
	{
		d[0]=n;
		c=0;
		for (i=1;i<10;i++)
		{
			j=i;
			d[i]=1;
			while (d[i]<n && j%n!=0)
			{
				j=j%n*10+i;
				d[i]++;
			}
			if (d[i]<d[c])
				c=i;
		}
		if (c!=0)
		{
			for (j=d[c];j>0;j--)
				printf("%d",c);
		}
		else{
			m=n;
			t=0;
			for (i=0;i<10;i++)
			{
				for (j=i+1;j<10;j++)
				{
					c=bfs(i,j,n,t);
					if (c!=-1 && c<m)
					{
						t=1-t;
						m=c;
					}
					else if (c==m)
					{
						for (k=m;k>=0;k--)
						{
							if (x[t][k]<x[1-t][k])
							{
								t=1-t;
								break;
							}
							else if (x[t][k]>x[1-t][k])
								break;
						}
					}
				}
			}
			for (i=m;i>=0;i--)
				printf("%d",x[1-t][i]);
		}
		printf("\n");
		scanf("%d",&n);
	}
	return 0;
}
