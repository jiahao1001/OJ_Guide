#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<utility>
using namespace std;
typedef pair<int,int> PII;
int v[26];
struct Gate{
    bool inv;
    bool linv,rinv;
    char type;
    Gate *l ,* r;
    Gate(){
        l = r = NULL;
        linv = rinv = inv = false;
    }
    bool eval(){
        bool ret;
        if(type>='A' && type<='Z') ret = v[type-'A']==1?true:false;
        else{
            bool lv = l->eval();
            bool rv = r->eval();
            if(linv) lv = !lv;
            if(rinv) rv = !rv;
            if(type==')') ret = lv&&rv;
            else ret = lv||rv;
        }
        if(inv) ret = !ret;
        return ret;
    }
};
char pic[100][120];
int vis[100][120];
char s[120];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
inline bool check(char c){
    if(c>='A' && c<='Z') return true;
    if(c=='o') return true;
    if(c==')') return true;
    if(c=='>') return true;
    return false;
}

Gate *build(int i,int j){
    vis[i][j] = 1;
    int x,y,nx,ny;
    while(true){
        x=i,y=j;
        if(check(pic[x][y])) break;
        for(int k=0;k<4;k++){
            nx = x+dx[k],ny = y+dy[k];
            if(pic[nx][ny]!=' ' && !vis[nx][ny]){
                i=nx,j=ny;
                vis[i][j] = 1;
                break;
            }
        }
    }
    char g = pic[x][y];
    Gate *root = new Gate();
    if(g=='o'){
        root->inv = true;
        y--;
        vis[x][y] = 1;
        g=pic[x][y];
    }
    if(g>='A' && g<='Z'){
        root->type = g;
        return root;
    }
    root->type = g;
    for(int i=-1;i<=1;i++)
        for(int j=1;j<=2;j++)
            vis[x+i][y-j] = 1;
    int li,lj;
    int ri,rj;
    li = x-1, lj = y-3;
    ri = x+1, rj = y-3;
    if(pic[li][lj]=='o'){
        vis[li][lj] = 1;
        lj--;
        root->linv = true;
    }
    if(pic[ri][rj]=='o'){
        vis[ri][rj]=1;
        rj--;
        root->rinv = true;
    }
    root->l = build(li,lj);
    root->r = build(ri,rj);
    return root;
}
int main()
{
    bool begin = true;
    while(gets(s)){
        memset(pic,' ',sizeof pic);
        memset(vis,0,sizeof vis);
        int len = strlen(s);
        int ri,rj;
        for(int j=0;j<len;j++){
            pic[1][1+j] = s[j];
            if(s[j]=='?') ri = 1, rj=1+j;
        }
        //pic[0][len] = 0;
        int n=1;
        while(gets(s),s[0]!='*'){
            ++n;
            len = strlen(s);
            for(int j=0;j<len;j++){
                pic[n][1+j] = s[j];
                if(s[j]=='?') ri = n, rj = 1+j;
            }
            //pic[n][len] = 0;
        }
        //bfs until a A, ) o >
        if(begin)begin=false;
        else
            printf("\n");
        vis[ri][rj] = 1;
        Gate *root = build(ri,rj);
        while(gets(s),s[0]!='*'){
            for(int i=0;i<26;i++)
                v[i] = s[i]-'0';
            if(root->eval())printf("1\n");
            else printf("0\n");
        }
    }
    return 0;
}

