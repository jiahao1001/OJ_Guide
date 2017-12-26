#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 40000;
struct Roof{
    int x1,y1,x2,y2;
    int w,next,deg;
    double k;
    int id;
} roof[N];
bool operator<(const Roof& r1,const Roof& r2){
    return r1.x1 < r2.x1;
}
int xs[2*N],p_cnt;
int n;
int v[30],cnt;
int w[N];
int main()
{
    int x1,y1,x2,y2;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        roof[i].x1 = x1;
        roof[i].y1 = y1;
        roof[i].x2 = x2;
        roof[i].y2 = y2;
        roof[i].k  = 1.0*(y2-y1)/(x2-x1);
        roof[i].id = i;
        roof[i].w  = 0;
        roof[i].deg = 0;
        roof[i].next = -1;
        xs[2*i] = x1;
        xs[2*i+1] = x2;
        
    }
    sort(xs,xs+2*n);
    p_cnt = unique(xs,xs+2*n) - xs;
    sort(roof,roof+n);
    //sweep line
    int x,last = 0;
    int t = 0,k;
    for(int i=0;i<p_cnt;last=x,i++){
        x = xs[i];
        //get water from sky
        if(cnt) roof[v[cnt-1]].w += x-last;
        while(t<n && roof[t].x1==x){
            k = -1;
            for(int j=0;j<cnt;j++)
                if(roof[v[j]].y1+roof[v[j]].k*(x-roof[v[j]].x1) < roof[t].y1) k = j;
            for(int j=cnt-1;j>k;j--)
                v[j+1] = v[j];
            cnt++;
            v[k+1] = t++;
        }
        //compute roof below
        for(int j=1;j<cnt;j++)
            if(roof[v[j]].x2==x && roof[v[j]].y1>roof[v[j]].y2 ||
               roof[v[j]].x1==x && roof[v[j]].y1<roof[v[j]].y2)
                roof[v[j]].next = v[j-1], roof[v[j-1]].deg++;
        k = 0;
        for(int j=0;j<cnt;j++)
            if(roof[v[j]].x2!=x) v[k++] = v[j];
        cnt = k;
    }
    //topological sort
    queue<int> q;
    for(int i=0;i<n;i++)
        if(!roof[i].deg) q.push(i);
    while(!q.empty()){
        int a = q.front();
        q.pop();
        int b = roof[a].next;
        if(b==-1) continue;
        roof[b].deg--;
        roof[b].w+=roof[a].w;
        if(!roof[b].deg) q.push(b);
    }
    
    for(int i=0;i<n;i++)
        w[roof[i].id] = roof[i].w;
    
    for(int i=0;i<n;i++)
        printf("%d\n",w[i]);
    
    return 0;
}
