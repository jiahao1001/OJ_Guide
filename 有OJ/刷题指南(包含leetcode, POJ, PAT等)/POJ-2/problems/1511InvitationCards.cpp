#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
using namespace std;

int T,N,M;
int u[1000010],v[1000010];
long long w[1000010];
vector<pair<int,long long> > g[1000010];
long long dist[1000010];
void dijkstra(){
	priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >PQ;
	for (int i=1;i<=N;i++) dist[i]=~0uLL>>2;
	dist[1]=0;
	PQ.push(make_pair(dist[1],1));
	while (!PQ.empty()){
		long long d=PQ.top().first;
		int a=PQ.top().second;
		PQ.pop();
		if (d!=dist[a]) continue;
		for(int i=0;i<g[a].size();i++){
                    pair<int,long long> p = g[a][i];
			if (dist[p.first]>d+p.second)
				PQ.push(make_pair(dist[p.first]=d+p.second,p.first));
                }
	}
}
int main(){
    scanf("%d",&T);
    while(T--){
        long long total = 0;
        scanf("%d%d",&N,&M);
        for(int i=0;i<M;i++)
            scanf("%d%d%lld",u+i,v+i,w+i);
        for(int i=1;i<=N;i++) g[i].clear();
        for(int i=0;i<M;i++)
            g[u[i]].push_back(make_pair(v[i],w[i]));
        
        dijkstra();
        //for(int i=1;i<=N;i++) cout<<dist[i]<<" ";
        for(int i=1;i<=N;i++) total += dist[i];
        
        for(int i=1;i<=N;i++) g[i].clear();
        for(int i=0;i<M;i++)
            g[v[i]].push_back(make_pair(u[i],w[i]));
        dijkstra();
        for(int i=1;i<=N;i++) total += dist[i];
        printf("%lld\n",total);
    }
    return 0;
}
