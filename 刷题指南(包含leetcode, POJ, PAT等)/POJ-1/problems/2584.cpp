#include<stdio.h>
#include<string.h>
#define MAX 30
#define MAXVALUE 999999
int numofnode,Flow[MAX][MAX],Residual[MAX][MAX];
int bfsnetworkflow();
int main()
{
	int m,i,j,k,size[5]={'S','M','L','X','T'};
	char str[30];
	while (scanf("%s",str),strcmp(str,"ENDOFINPUT")!=0)
	{
		memset(Flow,0,sizeof(Flow));
		memset(Residual,0,sizeof(Residual));
		scanf("%d",&m);
		numofnode=m+6;
		for (i=1;i<=m;i++)
		{
			Flow[0][i]=1;
			scanf("%s",str);
			for (j=0;j<5;j++)
				if (size[j]==str[0])
					break;
			for (k=j;k<5;k++)
				if (size[k]==str[1])
					break;
			while (j<=k)
			{
				Flow[i][j+m+1]=1;
				j++;
			}
		}
		for (i=0;i<5;i++)
		{
			scanf("%d",&j);
			Flow[m+1+i][numofnode]=j;
		}
		scanf("%s",str);
		if (bfsnetworkflow()==m)
			printf("T-shirts rock!\n");
		else printf("I'd rather not wear a shirt anyway...\n");
	}
	return 0;
}
int bfsnetworkflow()
{
	int prev[MAX],minflow[MAX],queue[MAX];
	int i,j,v,pr,qs,qe,w;
	minflow[0]=MAXVALUE;
	while(1)
	{
		for(i=0;i<MAX;i++)
			prev[i]=-2;
		prev[0]=-1;
		qs=0;
		qe=1;
		queue[qs]=0;
		while(qs<qe && prev[numofnode]==-2)
		{
			v=queue[qs++];
			for(i=0;i<numofnode+1;i++)
			{
				if(prev[i]==-2 && (pr=Flow[v][i]-Residual[v][i]))
				{
					prev[i]=v;
					queue[qe++]=i;
					minflow[i]=(minflow[v]<pr)?minflow[v]:pr;
				}
			} 
		} 
		if(prev[numofnode]==-2)
			break;
		for(i=prev[numofnode],j=numofnode;i!=-1;j=i,i=prev[i])
		{
			Residual[i][j]+=minflow[numofnode];
			Residual[j][i]=-Residual[i][j];
		}
	} 
	for(i=0,w=0;i<numofnode;i++) 
		w=w+Residual[i][numofnode];
	return w;
}
