#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
int n,c0,c1;
const int N = 3010;
int a[N],n0[N],n1[N],nxt[N];
int main(){
	scanf("%d",&n);
	c0=c1=0;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]) n1[++c1] = i;
		else n0[++c0] = i;
	}
	for(int i=1;i<=n;i++)
		if(i<=c0) nxt[i] = n0[i];
		else nxt[i] = n1[i-c0];
	int k=1;
	for(int i=1;i<=n;i++){
		if(i>1) printf(" ");
		printf("%d",k<=c0?0:1);
		k = nxt[k];
	}
    printf("\n");
	return 0;
}
