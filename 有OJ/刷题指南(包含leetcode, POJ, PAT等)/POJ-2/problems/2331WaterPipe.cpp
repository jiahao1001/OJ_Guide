#include<stdio.h>
#include<string.h>  
#include<queue>
using namespace std;
int sx,sy,tx,ty,n;
int len[5],num[5];
int bound,total;
int h[2]={1,-1};
int hx[1010],hy[1010];
bool ans;
struct point{
    int x;
    int step;
};

void bfs(int v,int * hx){
    int i,j,u,xx;
    queue<struct point>que;
    struct point sta;
    sta.step=0;
    sta.x=v;
    que.push(sta);
    hx[v]=0;
    while(!que.empty()){
        struct point tem;
        tem=que.front();
        que.pop();
        u=tem.x;
        for(i=0;i<2;i++){
            for(j=1;j<=n;j++){
                xx=u+len[j]*h[i];
                if(xx<=0 || xx>1000 || hx[xx]!=-1)
                    continue;
                if(hx[u]+1>total)
                    continue;
                hx[xx]=hx[u]+1;
                struct point cur;
                cur.step=hx[xx];
                cur.x=xx;
                que.push(cur);
            }

        }
        
    }
}

int dfs(int dep,int x,int *nu,int type){
    int i,j,xx,next_bound;
    if(type==0){
        if(dep+hx[x]+hy[sy]>bound)
            return dep+hx[x]+hy[sy];
        if(hx[x]==0)
            return dfs(dep,sy,nu,1);
    }
    else if(type==1){
        if(dep+hy[x]>bound)
            return dep+hy[x];
        if(hy[x]==0){
            ans=true;
            return dep;
        }
    }
    int tmp[5];
    for(i=1;i<=n;i++)
        tmp[i]= nu[i];
    
    int new_bound=1e7;
    for(i=0;i<2;i++){
        for(j=1;j<=n;j++)
            if(tmp[j]){
                tmp[j]--;
                xx=x+h[i]*len[j];
                if(xx<=0 || xx>1000 ){
		    tmp[j]++;
                    continue;
                }
                if(type==0){
                    if(hx[xx]==-1){
                        tmp[j]++;
                        continue;          
                    }
                }
                if(type==1){
                    if(hy[xx]==-1){
                        tmp[j]++;
                        continue;           
                    }
                }
                next_bound = dfs(dep+1,xx,tmp,type);
                if(!ans)
                    new_bound=min(new_bound,next_bound);
                else
                    return next_bound;
                tmp[j]++;
            }
    }
    return new_bound;
}

void IDA_STAR(){
    
    memset(hx,-1,sizeof(hx));
    memset(hy,-1,sizeof(hy));
    
    bfs(tx,hx);
    bfs(ty,hy);
    if(hx[sx]==-1 || hy[sy]==-1){
        printf("-1\n");
        return;
    }
    bound=hx[sx]+hy[sy];
    while(bound<=total && !ans){
        bound=dfs(0,sx,num,0);
    }
    if(ans)
        printf("%d\n",bound);
    else
        printf("-1\n");
}
int main(){
    int i,j;
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&len[i]);
    total=0;
    for(i=1;i<=n;i++){
        scanf("%d",&num[i]);
        total+=num[i];
    }
    ans=false;
    IDA_STAR();
}
