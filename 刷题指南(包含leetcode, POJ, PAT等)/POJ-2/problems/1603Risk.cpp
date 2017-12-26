#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <string.h>
#include <cctype>
using namespace std;
int g[21][21];
const int INF = 0x3f3f3f3f;
int main(){
	int cnt,b;
	int q = 1;
	while(scanf("%d",&cnt)!=-1){
		memset(g,0x3f,sizeof g);
		for(int i=0;i<cnt;i++){
			scanf("%d",&b);
			g[1][b] = g[b][1] = 1;
		}
		for(int i=2;i<=19;i++){
			scanf("%d",&cnt);
			for(int j=0;j<cnt;j++){
				scanf("%d",&b);
				g[i][b] = g[b][i] = 1;
			}
		}
		for(int k=1;k<=20;k++)
			for(int i=1;i<=20;i++)
				for(int j=1;j<=20;j++)
					if(g[i][k]+g[k][j]<g[i][j]) g[i][j] = g[i][k]+g[k][j];
		printf("Test Set #%d\n",q++);
		scanf("%d",&cnt);
		int a;
		for(int i=0;i<cnt;i++){
			scanf("%d%d",&a,&b);
			printf("%d to %d: %d\n",a,b,g[a][b]);
		}
		printf("\n");
	}
	return 0;
}
