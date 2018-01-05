#include<iostream>
#include<queue>
#include<cstring>
const int MAX = 100;
int fangxiang[8][2] = {{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int mark[MAX][MAX];
using namespace std;
typedef struct dian{
	int x, y, step;
};
int BFS(int x1, int y1, int x2, int y2){
	queue<dian> que;
	int x, y, i, j;
	dian n1, n2;
	n1.x = x1;
	n1.y = y1;
	n1.step = 0;
	que.push(n1);
	mark[x1][y1] = 1;
	while(!que.empty()){
		n1 = que.front();
		que.pop();
		if(n1.x == x2&&n1.y == y2)
		return n1.step;
		for(i=0; i < 8; i++){
			x = n2.x =n1.x + fangxiang[i][0];
			y = n2.y =n1.y + fangxiang[i][1];
			if(x>8||y>8||y<1||x<1||mark[x][y])
			continue;
			n2.step = n1.step + 1;
			mark[x][y] = 1;
			que.push(n2);
		}
	}
	return 0;
}
int main(){
	freopen("1372.in", "r", stdin);
	freopen("1372.out", "w", stdout);
	int i, j, k, a, x1, y1, x2, y2;
	char c1,c2;
	while(~scanf("%c%d %c%d", &c1,&x1,&c2,&x2)){
		getchar();
		memset(mark, 0, sizeof(mark));
		y1 = c1 -'a' + 1;
		y2 = c2 -'a' + 1;
		if(c1==c2&&x1==x2){
			printf("To get from %c%d to %c%d takes 0 knight moves.\n", c1, x1, c2, x2);
		}
		else{
			printf("To get from %c%d to %c%d takes %d knight moves.\n", c1,x1,c2,x2,BFS(x1,y1, x2, y2));
		}
	}
	return 0;
}
