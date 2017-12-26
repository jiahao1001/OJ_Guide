#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int T,n,m,R;
int rank[50000];
int Parent[20000];
struct Relation{
	int girl;
	int boy;
	int r;
}relation[50000];
int cmp(const void *a, const void *b)
{
	int x,y;
	x=*(int *)a;
	y=*(int *)b;
	if (relation[x].r<relation[y].r)
		return 1;
	else if (relation[x].r>relation[y].r)
		return -1;
	else return 0;
}

int root(int i){
	int r,p;
	for (r=i;Parent[r]>=0;r=Parent[r]);
	while (i!=r){
		p=i;
		i=Parent[i];
		Parent[p]=r;
	}	
	return r;
}
bool merge(int i,int j)//返回之前是否属于同一集合
{
	i=root(i);
	j=root(j);
	if (i==j) return true;
	if (Parent[i]<Parent[j]){
		Parent[i]+=Parent[j];
		Parent[j]=i;
		return false;
	}
	else {
		Parent[j]+=Parent[i];
		Parent[i]=j;
		return false;
	}
}
int kruskal(int n,int r)
{
	int result=0,i;
	qsort(rank,r,sizeof(rank[0]),cmp);
	for(i=0; i<r; i++ ){
		if(merge(relation[rank[i]].boy,relation[rank[i]].girl)==false)
			result+=relation[rank[i]].r;
	}
	return result;
}
int main()
{
	int r,t;
	int a,b;
	int min;
	scanf("%d",&T);
	for (t=0;t<T;t++)
	{
		scanf("%d%d%d",&n,&m,&R);
		memset(Parent,-1,sizeof(Parent));
		for (r=0;r<R;r++)
		{
			rank[r]=r;
			scanf("%d%d%d",&a,&b,&relation[r].r);
			relation[r].girl=a;
			relation[r].boy=b+n;
		}
		min=kruskal(n+m,R);
		min=10000*(n+m)-min;
		printf("%d\n",min);
	}
	return 0;
}
