#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char g[10][20];
const int n=10,m=15;
int v[10][20];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int que[200];
inline int cluster(int i,int j,bool remove){
    v[i][j] = 1;
    if(g[i][j]==' ') return 0;
    int s,t,tot = 1;
    s=t=0;
    v[i][j] = 1;
    char c = g[i][j];
    if(remove)g[i][j] =' ';
    que[t++] = i*m+j;
    while(s<t){
        int h = que[s++];
        int ii= h/m, jj = h%m;
        int x,y;
        for(int k=0;k<4;k++){
            x = ii+dx[k],y=jj+dy[k];
            if(x<0 || x>=n || y<0 || y>=m) continue;
            if(v[x][y] || g[x][y]!=c) continue;
            tot++;
            if(remove) g[x][y]=' ';
            v[x][y] = 1;
            que[t++] = x*m+y;
        }
    }
    return tot;
}
inline void fall(){
    for(int j=0;j<m;j++){
        // 1->0
        int k=0;
        for(int i=0;i<n;i++)
            if(g[i][j]!=' ') swap(g[i][j],g[k++][j]);
    }
    int k=0;
    for(int j=0;j<m;j++){
        //has one
        bool has = false;
        for(int i=0;i<n;i++)
            if(g[i][j]!=' '){
                has = true;
                break;
            }
        if(!has)continue;
        for(int i=0;i<n;i++)
            swap(g[i][k],g[i][j]);
        k++;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    char s[20];
    gets(s);
    for(int q=1;q<=t;q++){
        gets(s);
        for(int i=n-1;i>=0;i--)
            scanf("%s",g[i]);
        //n-1 0   0-m-1
        printf("Game %d:\n\n",q);
        int score = 0;
        int mv = 1;
        int balls = 0;
        while(true){
            int best = 1,x,y;
            memset(v,0,sizeof v);
            for(int j=0;j<=m-1;j++)
                for(int i=0;i<n;i++)
                    if(!v[i][j]){
                        int d = cluster(i,j,false);
                        if(d>best) best = d, x=i,y=j;
                    }
            if(best==1) break;
            balls += best;
            char c = g[x][y];
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",mv++,x+1,y+1,best,c,(best-2)*(best-2));
            score += (best-2)*(best-2);
            memset(v,0,sizeof v);
            cluster(x,y,true);
            fall();
            //for(int i=n-1;i>=0;i--)
            //  printf("%s\n",g[i]);
            
        }
        if(balls==150) score += 1000;
        printf("Final score: %d, with %d balls remaining.\n",score,150-balls);
        if(q!=t)printf("\n");
    }
    return 0;
}
