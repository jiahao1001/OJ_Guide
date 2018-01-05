#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
int lift[202], vis[202];
int n, a, b;
int main(){
	freopen("1548.in", "r", stdin);
	freopen("1548.out", "w", stdout);
	int i, m, x, y, f;
	while(scanf("%d", &n)==1){
		if(!n) break;
		scanf("%d%d", &a, &b);
		queue<int> q;
		memset(vis, 0, sizeof(vis));
		for(i=1; i <= n; i++)
		scanf("%d", &lift[i]);
		q.push(a);
		vis[a] = 0; 
		f = 0;
		while(!q.empty()){
			m = q.front();
			q.pop();
			if(m == b){
				f = 1; 
				break;
			}
			x = m - lift[m];
			if(x>0&&x<=n&&!vis[x]){
				vis[x]=vis[m]+1;
				q.push(x);
			}
			y = m + lift[m];
			if(y>0&&y<=n&&!vis[y]){
				vis[y] = vis[m] + 1;
				q.push(y);
			}
		}
	if(f)
	printf("%d\n", vis[b]);
	else
	printf("-1\n");
	}
return 0;
} 
