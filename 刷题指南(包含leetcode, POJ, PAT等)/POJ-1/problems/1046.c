#include<stdio.h>
int color[16][3];
int main()
{
	int x,y,z,i,min,map,m;
	for (i=0;i<16;i++)
		scanf("%d%d%d",&color[i][0],&color[i][1],&color[i][2]);
	scanf("%d%d%d",&x,&y,&z);
	while (x!=-1 || y!=-1 || z!=-1)
	{
		min=200000;
		for (i=0;i<16;i++)
		{
			m=(x-color[i][0])*(x-color[i][0])+(y-color[i][1])*(y-color[i][1])+(z-color[i][2])*(z-color[i][2]);
			if (m<min)
				min=m,map=i;
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,color[map][0],color[map][1],color[map][2]);
		scanf("%d%d%d",&x,&y,&z);
	}
	return 0;
}
