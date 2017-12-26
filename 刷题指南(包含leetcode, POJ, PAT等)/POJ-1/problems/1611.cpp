#include<stdio.h>
#include<string.h>
#define	COUNT	30000//数目	
int parent[COUNT];
int root(int i){
	int r,p;
	for (r=i;parent[r]>=0;r=parent[r]);
	while (i!=r){
		p=i;
		i=parent[i];
		parent[p]=r;
	}	
	return r;
}
bool merge(int i,int j)//返回之前是否属于同一集合
{
	i=root(i);
	j=root(j);
	if (i==j) return true;
	if (parent[i]<parent[j]){
		parent[i]+=parent[j];
		parent[j]=i;
		return false;
	}
	else {
		parent[j]+=parent[i];
		parent[i]=j;
		return false;
	}
}
int main()
{
	int a,b,i,j,k,n,m;
	while (scanf("%d%d",&n,&m),n!=0 || m!=0)
	{
		memset(parent,-1,sizeof(parent));//并查集预处理,首先将每个元素看作一个独立的集合
		for (i=0;i<m;i++)
		{
			scanf("%d%d",&k,&a);
			a=root(a);
			for (j=1;j<k;j++)
			{
				scanf("%d",&b);
				merge(a,b);
			}
		}
		a=root(0);
		b=1;
		for (i=1;i<n;i++)
		{
			if (root(i)==a)
				b++;
		}
		printf("%d\n",b);
	}
	return 0;
}