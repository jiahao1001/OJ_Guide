#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int K[1001];
struct Argus{
	int num;
	int period;
	int rear;
}argu[1000];
void ADJUST(int i,int n);
void HEAP(int n,int m);
int cmp(const void *a, const void *b);
int main()
{
	int n=0,m;
	char str[100];
	scanf("%s",str);
	while (strcmp(str,"#")!=0)
	{
		scanf("%d%d",&argu[n].num,&argu[n].period);
		argu[n].rear=1;
		n++;
		K[n]=argu[n-1].period;
		scanf("%s",str);
	}
	qsort(argu,n,sizeof(argu[0]),cmp);
	scanf("%d",&m);
	HEAP(n,m);
	return 0;
}
void ADJUST(int i,int n)
{
	int j;
	int temp=K[i];
	j=i<<1;
	while (j<=n)
	{
		if (j<n && K[j]>K[j+1])
			j++;
		if (temp<=K[j])
			break;
		K[j>>1]=K[j];
		j=j<<1;
	}
	K[j>>1]=temp;
}
void HEAP(int n,int m)
{
	int i,j;
	for (i=n/2;i>=1;i--)
		ADJUST(i,n);
	for (i=m;i>0;i--)
	{
		for (j=0;j<n;j++)
			if (K[1]==argu[j].period*argu[j].rear)
				break;
		printf("%d\n",argu[j].num);
		K[1]+=argu[j].period;
		argu[j].rear++;
		ADJUST(1,n);
	}
}
int cmp(const void *a, const void *b)
{
	struct Argus x,y;
	x=*(struct Argus *)a;
	y=*(struct Argus *)b;
	if (x.num<y.num)
		return -1;
	else if (x.num>y.num)
		return 1;
	else return 0;
}
