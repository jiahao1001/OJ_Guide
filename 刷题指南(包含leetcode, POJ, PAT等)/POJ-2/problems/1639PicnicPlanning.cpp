#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
map<string,int> name;
const int N = 30;
const int E = N*N;
const int inf = 0x7f7f7f7f;
int lim;
struct Prim{
	Prim(){
		memset(w,0x7f,sizeof w);
	}
	void insert(int u,int v, int c){
		w[u][v] = min(w[u][v],c);
	}
	int minDegreeST(int v0, int k){ // v0是限制度的点， k是限制的度数
		memset(father, -1, sizeof(father));
		memset(vis, 0, sizeof(vis));
		memset(edge, 0, sizeof(edge));
		vis[v0] = true;
		int m = 0;  // 连通分支的个数
		mst = 0;         // 所求答案

		/* 步骤1: 先求出m限制树 */
		for(int i=1; i<=n; ++i)if(!vis[i]){
			++m;
			mst += prim(i, v0);
		}
		/* 步骤2: 由m限制树得到m+1限制树 */
		int minAdd, a, b, tmp;
		int change;  // 回路上权值最大的边，用于交换
		for(int i=m+1; i<=k&&i<=n; ++i){
			memset(best, -1, sizeof(best));
			for(int j=1; j<=n; ++j)if(best[j]==-1 && father[j]!=v0){
				Best(j, v0);
			} 
			minAdd = inf;
			for(int j=1; j<=n; ++j)if(w[v0][j]!=inf && father[j]!=v0){ //遍历所有边
				a = best[j];
				b = father[best[j]];
				tmp = w[v0][j] - w[a][b];
				if(tmp < minAdd){
					minAdd=tmp;
					change = j;
				}
			}
			if(minAdd >= 0) break; //用于度数不大于k的限制，如果k限制，就不用break了
			mst += minAdd;
			a = best[change];
			b = father[change];
			w[a][b] = w[b][a] = inf;
			father[a] = b = v0;
			w[a][b] = w[b][a] = w[change][v0];
			w[v0][change] = w[change][v0] = inf;
		} 
		return mst;

	}


	void dfs(int cur){
		for(int i=1;i<=n;i++)
			if(mark[i] && edge[i][cur]){
				father[i] = cur;
				mark[i] = 0;
				dfs(i);
			}
	}
	int Best(int x,int V0){
		if(father[x] == V0) return -1;
		if(best[x] !=-1) return best[x];
		int tmp = Best(father[x],V0);
		if(tmp!=-1 && w[tmp][father[tmp]] > w[father[x]][x])
			best[x] = tmp;
		else best[x] = x;
		return best[x];
	}
	int prim(int s,int V0){
		memset(mark,0,sizeof mark);
		vis[s] = mark[s] = true;
		for(int i=1;i<=n;i++)
			key[i] = w[s][i], pre[i] = s;
		int sum = 0;
		for(int i=1;i<n;i++){
			int u = -1;
			for(int j=1;j<=n;j++)
				if(!vis[j] && !mark[j]){
					if(u==-1 || key[j]<key[u]) u=j;
				}
			if(u==-1) break;
			vis[u] = mark[u] = true;
			edge[pre[u]][u] = edge[u][pre[u]] = true;
			sum += w[pre[u]][u];
			for(int j=1;j<=n;j++) if(!vis[j] && !mark[j]){
				if(key[j]>w[u][j]) key[j] = w[u][j], pre[j]= u;
			}
		}
		int m = inf, root = -1;
		for(int i=1;i<=n;i++) if(mark[i] && w[i][V0] <m){
			m = w[i][V0];
			root = i;
		}
		mark[root] = 0;
		dfs(root);
		father[root] = V0;
		return sum+m;
	}
	int n,pre[N],father[N];
	bool edge[N][N],vis[N],mark[N];
	int mst,w[N][N],key[N];
	int best[N];

} G;
int main(){
	int n, d, a, b;
	string name1,name2;
	name["Park"] = 1;
	scanf("%d",&n);
	int cnt=1;
	for(int i=0; i<n; ++i){
		cin >> name1 >> name2 >> d;
		a=name[name1];  b=name[name2];
		if(!a)a=name[name1]=++cnt;
		if(!b)b=name[name2]=++cnt;
		G.insert(a,b,d);
		G.insert(b,a,d);
	}
	G.n = cnt;
	scanf("%d",&lim);
	printf("Total miles driven: %d\n", G.minDegreeST(1, lim));
	return 0;
}

