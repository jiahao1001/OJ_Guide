#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 10010;
struct Edge{
    int v,l;
    Edge(){};
    Edge(int _v,int _l):v(_v),l(_l){}
};
vector<Edge> g[N];
int n,k,size,s[N],f[N],root,d[N],K,ans;
vector<int> dep;
bool done[N];
void getroot(int now, int fa){
    int u;
    s[now]=1, f[now] = 0;
    for(int i=0;i<g[now].size();i++)
        if((u=g[now][i].v)!=fa && !done[u]){
            getroot(u,now);
            s[now]+=s[u];
            f[now] = max(f[now],s[u]);
        }
    f[now] = max(f[now],size-s[now]);
    if(f[now]<f[root]) root = now;
}
void getdep(int now,int fa){
    int u;
    dep.push_back(d[now]);
    s[now] =1;
    for(int i=0;i<g[now].size();i++)
        if((u=g[now][i].v)!=fa && !done[u]){
            d[u] = d[now]+g[now][i].l;
            getdep(u,now);
            s[now] += s[u];
        }
}

int calc(int now,int init){
    dep.clear();d[now] = init;
    getdep(now,0);
    sort(dep.begin(),dep.end());
    int ret = 0;
    for(int l=0,r=dep.size()-1;l<r;){
        if(dep[l]+dep[r]<=K) ret += r-l++;
        else r--;
    }
    return ret;
    
}

void work(int now){
    int u;
    ans += calc(now,0);
    done[now] = true;
    for(int i=0;i<g[now].size();i++){
        if(!done[u=g[now][i].v]){
            ans -= calc(u,g[now][i].l);
            f[0] = size = s[u];
            getroot(u,root=0);
            work(root);
        }
    }
}
int main()
{
    while (scanf("%d%d", &n, &K) == 2) {
        if (n == 0 && K == 0) break;
        for (int i=0; i<=n; i++) g[i].clear();
        memset(done, false, sizeof(done));
        
        int u, v, l;
        for (int i=1; i<n; i++) {
            scanf("%d%d%d", &u, &v, &l);
            g[u].push_back(Edge(v, l));
            g[v].push_back(Edge(u, l));
        }
        f[0] = size = n;
        getroot(1, root=0);
        ans = 0;
        work(root);
        printf("%d\n", ans);
    }  
    
    return 0;
}
