#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include <set>
using namespace std;
int d[6];
int t;
const int M = 1201;
inline int h(int x){
    return ((x%M)+M)%M;
}
struct Node{
    int k,v;
    int next;
};
struct Hash{
    int head[M];
    int cnt;
    Hash(){
        memset(head,-1,sizeof head);
        cnt = -1;
    }
    Node dt[50000];
    int get(int k){
        int p = head[h(k)];
        while(p!=-1){
            if(dt[p].k==k) return dt[p].v;
            p = dt[p].next;
        }
        return -1;
    }
    void put(int k,int v){
        int p = head[h(k)];
        head[h(k)] = ++cnt;
        dt[cnt].next = p;
        dt[cnt].k = k;
        dt[cnt].v = v;
    }
};
int bfs(int x){
	//x is goal money
	queue<int> Q;
	Hash m;//money -> step
    m.put(0,0);
	Q.push(0);
	while(!Q.empty()){
		int h = Q.front();
		Q.pop();
		if(h==x) return m.get(x);
		for(int i=0;i<6;i++)
			for(int j=-1;j<=1;j+=2){
				int y = h+j*d[i];
				if(m.get(y)!=-1) continue;
				m.put(y,m.get(h)+1);
				Q.push(y);
			}
	}
	return -1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<6;i++)
			scanf("%d",d+i);
		int cnt = 0;
		int m = 0;
		for(int i=1;i<=100;i++){
			int x = bfs(i);
			cnt += x, m = max(m,x);
		}
		printf("%.2f %d\n",cnt/100.0,m);
	}
	return 0;
}
