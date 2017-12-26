#include<stdio.h>
#include<string.h>
#define MAX 400010
char P[MAX];
int Pi[MAX],queue[MAX],m;
void Compute_PREFIX(char *P,int m);
int main()
{
	int i,j;
	while (scanf("%s",P)!=EOF)
	{
		m=strlen(P);
		Compute_PREFIX(P,m);
		j=0;
		i=m-1;
		while(Pi[i]>-1)
		{
			queue[j++]=Pi[i]+1;
			i=Pi[i];
		}
		for (i=j-1;i>=0;i--)
			printf("%d ",queue[i]);
		printf("%d\n",m);
	}
	return 0;
}
void Compute_PREFIX(char *P,int m)
{
	int q,k=-1;
	Pi[0]=-1;
	for (q=1;q<m;q++)
	{
		while (k>-1 && P[k+1]!=P[q])
			k=Pi[k];
		if (P[k+1]==P[q])
			k++;
		Pi[q]=k;
	}
}
