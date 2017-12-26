#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string.h>
using namespace std;
const int N = 250;
const int inf = INT_MAX/2;
int n,m;
int B[N][N],C[N][N]; // lower, upper
int f[N][N],CP[N][N];
int src,sink;

inline void cc(int i,int j,char c,int v){
    if(c=='>'){
        B[i][n+j] = max(B[i][n+j],v+1);
    }else if(c=='='){
        B[i][n+j] = max(B[i][n+j],v);
        C[i][n+j] = min(C[i][n+j],v);
    }else{
        C[i][n+j] = min(C[i][n+j],v-1);
    }
}
inline void change(int r,int q,char c,int v){
    if(r==0 && q==0){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) cc(i,j,c,v);
    }else if(r==0){
        for(int i=1;i<=n;i++) cc(i,q,c,v);
    }else if(q==0){
        for(int j=1;j<=m;j++) cc(r,j,c,v);
    }else cc(r,q,c,v);
}

int build_graph(){
    int sum = 0;
    src = n+m+2, sink = n+m+3;
    memset(CP,0,sizeof CP);
    int tot = n+m+1;
    for(int i=0;i<=tot;i++){
        int in = 0, out = 0;
        for(int j=0;j<=tot;j++)
            in+=B[j][i], out+=B[i][j];
        if(in-out>0) sum+=in-out,CP[src][i] = in-out;
        else CP[i][sink] = out-in;
    }
    for(int i=0;i<=tot;i++)
        for(int j=0;j<=tot;j++) CP[i][j] = C[i][j]-B[i][j];
    CP[tot][0] = inf;
    return sum;
}
int pre[N];
int que[N];
bool bfs(){
    memset(pre,-1,sizeof pre);
    int s,t;
    s=t=0;
    que[t++] = src;
    pre[src] = 0;
    while(s<t){
        int u = que[s++];
        if(u==sink) return true;
        for(int v=0;v<=sink;v++)
            if(pre[v]==-1 && CP[u][v]-f[u][v]>0) pre[v]=u, que[t++]=v;
    }
    return false;
}

int max_flow(){
    //EK
    memset(f,0,sizeof f);
    while(bfs()){
        int p=sink;
        int t=inf;
        for(;p!=src;p=pre[p]) t = min(t,CP[pre[p]][p]-f[pre[p]][p]);
        for(p=sink;p!=src;p=pre[p]) f[pre[p]][p]+=t, f[p][pre[p]]-=t;
    }
    int flow = 0;
    for(int i=0;i<=sink;i++) flow+=f[src][i];
    //printf("flow = %d\n",flow);
    
    return flow;
}

int main()
{
    int t,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        //n row, m column
        //0 src  n+m+1 sink
        memset(B,0,sizeof B);
        memset(C,0,sizeof C);
        int x;
        
        for(int i=1;i<=n;i++)
            scanf("%d",&x),B[0][i] = C[0][i] = x;
        for(int i=1;i<=m;i++)
            scanf("%d",&x),B[n+i][n+m+1] = C[n+i][n+m+1] = x;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) B[i][n+j] = 0, C[i][n+j] = inf;
        
        
        
        scanf("%d",&c);
        int r,q,v;
        char co;
        for(int i=0;i<c;i++){
            scanf("%d%d %c %d",&r,&q,&co,&v);
            change(r,q,co,v);
        }
        bool ok = true;
        for(int i=0;i<=n+m+1;i++)
            for(int j=0;j<=n+m+1;j++)
                if(B[i][j]>C[i][j]) ok = false;
        if(!ok){
            printf("IMPOSSIBLE\n");
            if(t)printf("\n");
            continue;
        }
        int sum = build_graph();
        //  printf("sum = %d\n",sum);
        if(sum>max_flow()){
            printf("IMPOSSIBLE\n");
            if(t)printf("\n");
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                printf("%d",B[i][n+j]+f[i][n+j]);
                if(j==m)printf("\n");
                else printf(" ");
            }
        if(t) printf("\n");
    }
    return 0;
}
