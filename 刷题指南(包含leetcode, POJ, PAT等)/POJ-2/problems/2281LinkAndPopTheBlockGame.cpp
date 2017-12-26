#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<map>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
const int N = 32;
const int M = 32;
int n,m;
char b[N][M];
char a[N][M];
int sumx[N][M],sumy[M][N];
inline int getx(int x,int y1,int y2){
    if(y1==0) return sumx[x][y2];
    else return sumx[x][y2]-sumx[x][y1-1];
}
inline int gety(int y,int x1,int x2){
    if(x1==0) return sumy[y][x2];
    else return sumy[y][x2]-sumy[y][x1-1];
}
inline int link(int x1,int y1,int x2,int y2){
    //(x1,y1)  (x2,y2)  can be link by exactly two segments
    if(x1==x2 || y1==y2) return false;
    if(x1>x2) swap(x1,x2), swap(y1,y2);
    if(y1<y2){
        //  y1y2 x2  x1x2 y1    or   y1y2 x1   x1x2 y2
        return min(getx(x2,y1,y2)+gety(y1,x1,x2),
                   getx(x1,y1,y2)+gety(y2,x1,x2) );
    }else{
        // x1x2 y1  y2y1 x2    or  x1x2 y2 y2y1 x1
        return min(gety(y1,x1,x2)+getx(x2,y2,y1),
                   gety(y2,x1,x2)+getx(x1,y2,y1));
    }
    
}
inline void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            printf("%c",b[i][j]);
        printf("\n");
        }
}
inline bool try_one(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(b[i][j]=='.') continue;
            //link right
            int k = j+1;
            for(k=j+1;k<=m;k++)
                if(b[i][k]!='.') break;
            if(b[i][j]==b[i][k]){
                //cout<<"find 1"<<b[i][j]<<endl;
                b[i][j] = b[i][k] = '.';
                return true;
            }
            //link dow
            k=i+1;
            for(k=i+1;k<=n;k++)
                if(b[k][j]!='.') break;
            if(b[i][j]==b[k][j]){
                //cout<<"find 1"<<b[i][j]<<endl;
                b[i][j] = b[k][j] = '.';
                return true;
            }
        }
    return false;
}
int locked[N][M];
map<char,PII> dirs;
vector<PII> pieces;
int move_piece(int i,int j){
    if(a[i][j]=='S') return 0;
    PII dir = dirs[a[i][j]];
    int x = i+dir.first, y = j+dir.second;
    if(x<=0 || x>n || y<=0 || y>m) return 0;
    if(b[x][y]!='.') return 0;
    swap(b[i][j],b[x][y]);
    swap(a[i][j],a[x][y]);
    locked[x][y] = 1;
    return 1;
}
inline bool loose(){
    memset(locked,0,sizeof locked);
    int cnt = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(locked[i][j] || b[i][j]=='.') continue;
            cnt += move_piece(i,j);
        }
    return cnt!=0;
}
inline void update(){
    //update sum
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++){
            int t = b[i][j]=='.'?0:1;
            if(i==0) sumy[j][i] = 0;
            else sumy[j][i] = sumy[j][i-1]+t;
            if(j==0) sumx[i][j] = 0;
            else sumx[i][j] = sumx[i][j-1]+t;
        }
}
inline bool merge_one(){
    if(!try_one()) return false;
    while(loose()){}
    return true;
}

inline bool try_two(){
    //eliminate and return true
    pieces.clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(b[i][j]!='.') pieces.push_back(make_pair(i,j));
    int x1,y1,x2,y2;
    for(int i=0;i<pieces.size();i++)
        for(int j=i+1;j<pieces.size();j++){
            x1 = pieces[i].first, y1 = pieces[i].second;
            x2 = pieces[j].first, y2 = pieces[j].second;
            if(b[x1][y1]!=b[x2][y2]) continue;
            if(link(x1,y1,x2,y2)==2){
                //cout<<"find 2"<<b[x2][y2];
                b[x1][y1] = b[x2][y2] = '.';
                return true;
            }
        }
    return false;
}

inline bool merge_two(){
    if(!try_two()) return false;
    while(loose()){}
    return true;
}

inline bool try_three(){
    pieces.clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(b[i][j]!='.') pieces.push_back(make_pair(i,j));
    int x1,y1,x2,y2;
    for(int i=0;i<pieces.size();i++)
        for(int j=i+1;j<pieces.size();j++){
            x1 = pieces[i].first, y1 = pieces[i].second;
            x2 = pieces[j].first, y2 = pieces[j].second;
            if(b[x1][y1]!=b[x2][y2]) continue;
            int k;
            //up
            for(k=x1-1;k>=0;k--){
                if(b[k][y1]!='.') break;
                if(link(k,y1,x2,y2)==1){
                    b[x1][y1] = b[x2][y2] = '.';
                    return true;
                }
            }
            
            //down
            for(k=x1+1;k<=n+1;k++){
                if(b[k][y1]!='.') break;
                if(link(k,y1,x2,y2)==1){
                    b[x1][y1] = b[x2][y2] = '.';
                    return true;
                }
            }
            
            //left
            for(k=y1-1;k>=0;k--){
                if(b[x1][k]!='.') break;
                if(link(x1,k,x2,y2)==1){
                    b[x1][y1] = b[x2][y2] = '.';
                    return true;
                }
            }
            
            //right
            for(k=y1+1;k<=m+1;k++){
                if(b[x1][k]!='.') break;
                if(link(x1,k,x2,y2)==1){
                    b[x1][y1] = b[x2][y2] = '.';
                    return true;
                }
            }
        }
    return false;
}



inline bool merge_three(){
    if(!try_three()) return false;
    while(loose()){}
    return true;
}
int main()
{
    int q=1;
    char p[5];
    dirs['U'] = make_pair(-1,0);
    dirs['D'] = make_pair(1,0);
    dirs['L'] = make_pair(0,-1);
    dirs['R'] = make_pair(0,1);
    while(scanf("%d%d",&n,&m),n||m){
        memset(b,'.',sizeof b);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                scanf("%s",p);
                b[i][j] = p[0];
                a[i][j] = p[1];
            }
        
        while(true){
            if(merge_one()) update();
            else if(merge_two()) update();
            else if(merge_three()) update();
            else break;
        }
        printf("Case %d\n",q++);
        print();
        
        
    }
    return 0;
}
