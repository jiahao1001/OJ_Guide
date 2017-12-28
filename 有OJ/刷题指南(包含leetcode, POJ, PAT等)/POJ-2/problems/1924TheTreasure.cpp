#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
#include<utility>
#include<stdio.h>
using namespace std;
typedef pair<int,int> PI;
char bd[101][100][110];
int pm;
int n,m;
vector<vector<PI> > monster;
PI p,t;
vector<char> mm;//a or n
int dist[101][100][100];
int dx[8]={0,0,-1,-1,-1,1,1,1};
int dy[8]={1,-1,1,0,-1,1,0,-1};
bool attack(int k,int x,int y){
    if(bd[k][x][y]=='n' || bd[k][x][y]=='a') return true;
    int i,j;
    for(int dir = 0; dir<8;dir++){
        i = x+dx[dir], j = y+dy[dir];
        if(i<0 || i>=n || j<0 || j>=m) continue;
        if(bd[k][i][j]=='a') return true;
    }
    return false;
}
int bfs(){
    memset(dist,-1,sizeof dist);
    dist[0][p.first][p.second] = 0;
    queue<PI> Q;
    Q.push(make_pair(0,p.first*m+p.second));
    int x,y;
    while(!Q.empty()){
        PI h = Q.front();
        Q.pop();
        int i = h.second/m, j = h.second%m;
        int d = dist[h.first][i][j];
        
        if(h.second == t.first*m + t.second) return d;
        if(d==100) continue; //cut-off
        //monsters move
        if(attack(d+1,i,j)) continue; //die
        else{
            if(dist[d+1][i][j]==-1) dist[d+1][i][j] = d+1, Q.push(make_pair(d+1,i*m+j));
        }
        for(int k = 0;k<8;k++){
            for(int st = 1;st<=2;st++){
                x = i+dx[k]*st, y = j+dy[k]*st;
                //printf("x y %d,%d\n",x,y);
                if(x<0 || x>=n || y<0 || y>=m || bd[d+1][x][y]=='#') break;
                if(attack(d+1,x,y)) break;
                if(dist[d+1][x][y]!=-1) continue;
                dist[d+1][x][y] = d+1;
                Q.push(make_pair(d+1,x*m+y));
            }
        }
    }
    return -1;
}
int main()
{
    bool begin = true;
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<n;i++)
            scanf("%s",bd[0][i]);
        scanf("%d",&pm);
        monster.clear();
        mm.clear();
        int cnt,x,y;
        for(int i=0;i<pm;i++){
            monster.push_back(vector<PI>());
            scanf("%d",&cnt);
            for(int j=0;j<cnt;j++){
                scanf("%d%d",&x,&y);
                x--,y--;
                monster.back().push_back(make_pair(x,y));
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(bd[0][i][j]=='#' || bd[0][i][j] == '.') continue;
                char c = bd[0][i][j];
                if(c=='t') t = make_pair(i,j);
                else if(c=='p') p = make_pair(i,j);
                else if(c=='a') mm.push_back('a');
                else if(c=='n') mm.push_back('n');
                bd[0][i][j] = '.';
            }
        for(int k=1;k<=100;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++) bd[k][i][j] = bd[k-1][i][j];
        for(int k=0;k<=100;k++)
            for(int i=0;i<mm.size();i++){
                PI &tmp = monster[i][k%monster[i].size()];
                x = tmp.first, y = tmp.second;
                if(bd[k][x][y]=='#') continue;
                char c = mm[i];
                if(c=='a') bd[k][x][y] = 'a';
                else if(c=='n' && bd[k][x][y]!='a') bd[k][x][y] = 'n';
            }
        int ans = bfs();
        if(begin) begin = false;
        else printf("\n");
        if(ans==-1)printf("impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}
