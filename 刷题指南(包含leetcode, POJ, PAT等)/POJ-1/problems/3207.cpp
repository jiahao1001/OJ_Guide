#include<stdio.h>
int point[2][500];
int main()
{
	int i,j,m,n,temp;
	bool f;
	scanf("%d%d",&n,&m);
	for (i=0;i<m;i++)
	{
		scanf("%d%d",&point[0][i],&point[1][i]);
		if (point[0][i]>point[1][i])
		{
			temp=point[0][i];
			point[0][i]=point[1][i];
			point[1][i]=temp;
		}
	}
	for (i=0;i<m;i++)
	{
		f=false;
		for (j=0;j<m;j++)
		{
			if ((point[0][i]>=point[0][j] && point[1][i]>=point[1][j]) || (point[0][i]<=point[0][j] && point[1][i]<=point[1][j]))
				continue;
			else if (f==true && !((point[0][temp]>=point[0][j] && point[1][temp]>=point[1][j]) || (point[0][temp]<=point[0][j] && point[1][temp]<=point[1][j])))
				break;
			else {
				f=true;
				temp=j;
			}
		}
		if (j<m)
			break;
	}
	if (i<m)
		printf("the evil panda is lying again\n");
	else printf("panda is telling the truth...\n");
	return 0;
}
