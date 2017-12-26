#include<iostream>
#include<string>
#include<map>
#include<queue>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int s[10][10],t[10][10],D,N;
int tmp[10][10];
char cmd[20];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
string encode(int b[][10]){
    string r="";
    for(int i=0;i<D;i++)
        for(int j=0;j<D;j++){
            r+=('0'+b[i][j]/10);
            r+=('0'+b[i][j]%10);
        }
    return r;
}
void decode(string ss,int b[][10]){
    int cur = 0;
    for(int i=0;i<D;i++)
        for(int j=0;j<D;j++){
            b[i][j] = atoi(ss.substr(cur,2).c_str());
            cur+=2;
        }
    
}
int search(queue<string> &q,map<string,int> &d0, map<string,int>& d1){
    int size = q.size();
    int x,y;
    int d;
    for(int m=0;m<size;m++){
        string h = q.front();
        //cout<<"h "<<h<<endl;
        q.pop();
        decode(h,tmp);
        /*for(int i=0;i<D;i++){
            for(int j=0;j<D;j++)
                printf("%d ",tmp[i][j]);
            printf("\n");
            }*/
        
        d = d0[h];
        int i=0,j=0;
        for(i=0;i<D;i++){
            for(j=0;j<D;j++)
                if(tmp[i][j]==0) break;
            if(j!=D && tmp[i][j]==0) break;
        }
        //printf("(%d,%d)\n",i,j);
        for(int k=0;k<4;k++){
            x = i+dx[k], y = j+dy[k];
            if(x<0 || x>= D || y<0 || y>=D) continue;
            swap(tmp[i][j],tmp[x][y]);
            string ns = encode(tmp);
            //cout<<" Ns "<<ns<<endl;
            if(d1.count(ns)) return d+1+d1[ns];
            if(!d0.count(ns)) d0[ns] = d+1, q.push(ns);
            swap(tmp[i][j],tmp[x][y]);
        }
    }
    return -1;
}
int bfs(){
    string ss = encode(s);
    string tt = encode(t);
    if(ss==tt) return 0;
    map<string,int> d0,d1;
    queue<string> q0,q1;
    d0[ss] = 0, d1[tt] = 0;
    q0.push(ss), q1.push(tt);
    int td = 0;
    if(td==N) return -1;
    while(!q0.empty() || !q1.empty()){
        int dd;
        dd=search(q0,d0,d1);
        if(dd!=-1) return dd;
        td++;
        if(td==N) break;
        dd = search(q1,d1,d0);
        if(dd!=-1) return dd;
        td++;
        if(td==N) break;
    }
    
    return -1;
}
int main()
{
    bool begin = true;
    while(scanf("%s%d%d",cmd,&D,&N)!=EOF){
        char tk[10];
        for(int i=0;i<D;i++)
            for(int j=0;j<D;j++){
                scanf("%s",tk);
                if(tk[0]=='X') s[i][j] = 0;
                else s[i][j] = atoi(tk);
            }
        for(int i=0;i<D;i++)
            for(int j=0;j<D;j++){
                scanf("%s",tk);
                if(tk[0]=='X') t[i][j] = 0;
                else t[i][j] = atoi(tk);
            }
        scanf("%s",cmd);
        if(begin) begin = false;
        else printf("\n");
        int ans = bfs();
        if(ans==-1) printf("NOT SOLVABLE WITHIN %d MOVES\n",N);
        else printf("SOLVABLE WITHIN %d MOVES\n",ans);
    }
    return 0;
}
