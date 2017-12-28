#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N = 1000;
const double eps = 1e-9;
struct Point{
    int x,y;
};
struct Wall{
    Point p1,p2;
    char type;
} wall[N];
double wood[N][N];//wood length between wall (i,j)
bool between(int a,int b,int c){
    return b<=a && a<=c;
}
inline double sqr(double x){
    return x*x;
}
inline double dist(Point p1,Point p2){
    return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}
double end_to_end(Wall w1,Wall w2){
    return min(dist(w1.p1,w2.p1),min(dist(w1.p1,w2.p2),min(dist(w1.p2,w2.p1),dist(w1.p2,w2.p2))));
}
double h_wood(Wall w1,Wall w2){
    if(between(w1.p1.x,w2.p1.x,w2.p2.x) || between(w1.p2.x,w2.p1.x,w2.p2.x)  
    || between(w2.p1.x,w1.p1.x,w1.p2.x) || between(w2.p2.x,w1.p1.x,w1.p2.x))
        return abs(w1.p1.y-w2.p1.y);
    else return end_to_end(w1,w2);
}
double v_wood(Wall w1,Wall w2){
    double yd = max(w1.p1.y,w2.p1.y);
    double yu = min(w1.p2.y, w2.p2.y);
    if(yd<=yu) return abs(w1.p1.x-w2.p2.x);
    else return end_to_end(w1,w2);
}
double hv_wood(Wall w1,Wall w2){
    if(w1.type=='h') swap(w1,w2);  //  v  --
    if(between(w1.p1.x, w2.p1.x, w2.p2.x) && between(w2.p1.y, w1.p1.y, w1.p2.y)) return 0;
    else if(between(w1.p1.x, w2.p1.x, w2.p2.x)) return min(abs(w1.p1.y-w2.p1.y),abs(w1.p2.y-w2.p1.y));
    else if(between(w2.p1.y, w1.p1.y, w1.p2.y)) return min(abs(w1.p1.x-w2.p1.x),abs(w1.p1.x-w2.p2.x));
    else return end_to_end(w1,w2);
}

double wood_length(Wall w1, Wall w2){
    if(w1.type=='h' && w2.type=='h')
        return h_wood(w1,w2);
    else if(w1.type=='v' && w2.type == 'v')
        return v_wood(w1,w2);
    else return hv_wood(w1,w2);
}
int n;
int visited[N];
bool check(double len){
    //bfs  0->1
    memset(visited,0,sizeof(visited));
    visited[0] = 1;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int head = Q.front();
        Q.pop();
        if(head==1) return true;
        for(int i=0;i<n;i++)
            if(!visited[i] && wood[head][i]<len+eps) Q.push(i),visited[i] = 1;
    }
    return false;
}
int main()
{
    int x,y,L;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&L);
            if(L>=0){
                wall[i].type = 'h';
                wall[i].p1.x = x, wall[i].p1.y = y;
                wall[i].p2.x = x+L, wall[i].p2.y = y;
            }else{
                wall[i].type = 'v';
                wall[i].p1.x = x, wall[i].p1.y = y;
                wall[i].p2.x = x, wall[i].p2.y = y-L;
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) wood[i][j] = wood_length(wall[i],wall[j]);
        double l = 0, r = wood[0][1];
        double mid;
        while(fabs(l-r)>eps){
            mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%.2f\n",r);
        
    }
    return 0;
}
