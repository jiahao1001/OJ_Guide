#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
	{ return x>y?1:0; }
int main()
{
	int n;
	int buf[100];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&buf[i]);
		sort(buf,buf+n,cmp);
		for(i=0;i<n;i++)
			printf("%d ",buf[i]);
		printf("\n");
	}
	return 0;
}