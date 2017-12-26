#include<stdio.h>
#include<string.h>
int neighbor[10],place[10],lake[10][10]={0},n;
void sort(int p)
{
	int j,k,temp;
	for (j=p;j<n;j++)
	{
		for (k=j+1;k<n;k++)
		{
			if (neighbor[j]<neighbor[k])
			{
				temp=neighbor[j];
				neighbor[j]=neighbor[k];
				neighbor[k]=temp;
				temp=place[j];
				place[j]=place[k];
				place[k]=temp;
			}
		}
	}
}
int main()
{
    int t,i,j,k;
	scanf("%d",&t);
	for (i=0;i<t;i++)
	{
		scanf("%d",&n);
		for (j=0;j<n;j++)
		{
			scanf("%d",&neighbor[j]);
			place[j]=j;
		}
		for (j=0;j<n;j++)
		{
			sort(j);
			for (k=j+1;neighbor[j]>0 && k<n;k++)
			{
				if (neighbor[k]>0)
				{
					neighbor[j]--;
					neighbor[k]--;
					lake[place[j]][place[k]]=1;
					lake[place[k]][place[j]]=1;
				}
			}
			if (neighbor[j]>0)
				break;
		}
		if (j==n)
		{
			printf("YES\n");
			for (j=0;j<n;j++)
			{
				for (k=0;k<n;k++)
					printf("%d ",lake[j][k]);
				printf("\n");
			}
			printf("\n");
		}
		else printf("NO\n\n");
		memset(lake,0,sizeof(lake));
	}
	return 0;
}
