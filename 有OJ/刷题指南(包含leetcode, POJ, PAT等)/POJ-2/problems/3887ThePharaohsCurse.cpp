#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int N = 150;
int id[2501];
int real[N+1];
int h,w;
struct Config{
    int p,s1,s2;
    Config(int _p,int _s1,int _s2):p(_p),s1(_s1),s2(_s2){}
    Config(){}
} Q[200*200*200];
inline bool operator==(const Config& c1, const Config &c2){
    //c2 is final
    if(c1.p!=c2.p) return false;
    if(c2.s1==N) return true;
    if(c2.s2==N) return c2.s1 == c1.s1 || c2.s1 == c1.s2;
    return c1.s1 == c2.s1 && c1.s2 == c2.s2;
    
}
int dist[N+1][N+1][N+1];
char tomb[50][60];
int x_cnt=0, b_cnt=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int empty(int i,int j){
    return i>=0 && i<h && j>=0 && j<w && tomb[i][j]!='#';
}
int cnt;
int bfs(){
    memset(dist,-1,sizeof(dist));
    cnt = 0;
    x_cnt =0 ,b_cnt = 0;
    int b[2],x[2];
    b[0]=b[1] = h*w, x[0]=x[1] = h*w;
    int s,e;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            if(tomb[i][j]=='S') s = i*w+j;
            else if(tomb[i][j]=='X') x[x_cnt++] = i*w+j;
            else if(tomb[i][j]=='B') b[b_cnt++] = i*w+j;
            else if(tomb[i][j]=='E') e=i*w+j;
            if(tomb[i][j]!='#') id[i*w+j] = cnt++, real[cnt-1] = i*w+j;
            
        }
    
    id[h*w] = N;
    real[N] = h*w;
    s = id[s], e = id[e];
    x[0] = id[x[0]],x[1]=id[x[1]], b[0]=id[b[0]],b[1]=id[b[1]];
    if(x[0]>x[1]) swap(x[0],x[1]);
    if(b[0]>b[1]) swap(b[0],b[1]);
    Config initial(s,x[0],x[1]);
    Config final(e,b[0],b[1]);
    int q_s=0,q_t=0;
    Q[q_t++]=initial;
    dist[s][x[0]][x[1]] = 0;
    int p,x1,x2;
    int pi,pj,x1i,x2i,x1j,x2j;
    int npi,npj,nx1i,nx2i,nx1j,nx2j;
    
    while(q_s<q_t){
        Config head = Q[q_s++];
        p = head.p, x1 = head.s1, x2 = head.s2;
        int d = dist[p][x1][x2];
        p = real[p], x1 = real[x1],x2=real[x2];
        bool has_two = true;
        if(x2==h*w) has_two = false;
        if(head==final) {
            return d;
        }
        pi = p/w, pj = p%w, x1i = x1/w, x1j = x1%w, x2i = x2/w, x2j = x2%w;
        for(int k=0;k<4;k++){
            nx1i = x1i, nx1j = x1j, nx2i = x2i, nx2j = x2j;
            npi = pi+dx[k], npj = pj+dy[k];
            if(!empty(npi,npj)) continue;
            
            //try box 1
            if(npi==nx1i && npj == nx1j){
                //need push
                nx1i+=dx[k],nx1j+=dy[k];
                if(!empty(nx1i,nx1j)) continue;
                if(nx1i==nx2i && nx1j==nx2j) continue;
            }
            if(has_two){
                //try box 2
                if(npi==nx2i && npj == nx2j){
                    nx2i+=dx[k],nx2j+=dy[k];
                    if(!empty(nx2i,nx2j)) continue;
                    if(nx1i==nx2i && nx1j==nx2j) continue;
                }
            }
            p = id[npi*w+npj], x1 = id[nx1i*w+nx1j], x2 = id[nx2i*w+nx2j];
            if(x1>x2) swap(x1,x2);
            if(dist[p][x1][x2]!=-1) continue;
            dist[p][x1][x2] = d+1;
            Q[q_t++]=Config(p,x1,x2);
            
            
        }
        
        
    }
    return -1;
    
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&h,&w);
        x_cnt = b_cnt = 0;
        for(int i=0;i<h;i++) {
            scanf("%s",tomb[i]);
            for(int j=0;j<w;j++) {
                if(tomb[i][j]=='X') x_cnt++;
                else if(tomb[i][j]=='B') b_cnt++;
            }
        }
        if(x_cnt<b_cnt){
            printf("impossible\n");
            continue;
        }
        
        int answer = bfs();
        if(answer==-1)printf("impossible\n");
        else printf("%d\n",answer);
    }
    return 0;
}
