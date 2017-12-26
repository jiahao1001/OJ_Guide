#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
int n,m;
struct Point {
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
};
vector<Point> black,white;
Point operator-(const Point &p1,const Point &p2){
    Point p(0,0);
    p.x = p1.x - p2.x;
    p.y = p1.y - p2.y;
    return p;
    
}
bool operator==(const Point &p1,const Point &p2){
    return p1.x==p2.x && p1.y==p2.y;
}
int cross(const Point &p1,const Point &p2){
    return p1.x*p2.y-p2.x*p1.y;
}
struct Seg{
    Point p1,p2;
};
vector<Seg> bs,whs;
int ccw(Point p0,Point p1,Point p2){
    p1 = p1-p0;
    p2 = p2-p0;
    return cross(p1,p2);
}
bool intersect(const Seg &s1, const Seg &s2){
    if(s1.p1 == s2.p1 || s1.p1==s2.p2 || s1.p2 == s2.p1 || s1.p2==s2.p2) return false;
    
    return ccw(s1.p1,s1.p2,s2.p1)*ccw(s1.p1,s1.p2,s2.p2)<0 &&
    ccw(s2.p1,s2.p2,s1.p1)*ccw(s2.p1,s2.p2,s1.p2)<0;
}
void add_peg(int x,int y,vector<Point>& black,vector<Seg>& bbs){
    //try to connect black
    for(int j=0;j<black.size();j++){
        Point &p = black[j];
        //knight move and no intersection
        int d1 = abs(p.x-x);
        int d2 = abs(p.y-y);
        if(d1+d2!=3 || !d1 ||!d2) continue;
        //bs,ws;
        Seg s;
        s.p1 = Point(x,y);
        s.p2 = p;
        bool good = true;
        for(int k=0;k<bs.size();k++){
            if(intersect(s,bs[k])){
                good =false;
                break;
            }
        }
        for(int k=0;k<whs.size();k++){
            if(intersect(s,whs[k])){
                good =false;
                break;
            }
        }
        if(good) bbs.push_back(s);
    }
    black.push_back(Point(x,y));
}
int f[500],rk[500];//union find
int find_set(int x){
    if(f[x]==x) return x;
    int r = find_set(f[x]);
    return f[x] = r;
}
void union_set(int x,int y){
    x = find_set(x), y = find_set(y);
    if(x==y) return;
    if(rk[x]<rk[y]) f[x] = y;
    else{
        f[y] = x;
        if(rk[x]==rk[y]) rk[x]++;
    }
}
bool check(){
    for(int i=0;i<black.size();i++)
        for(int j=0;j<black.size();j++)
            if(black[i].x==0 && black[j].x==n && find_set(black[i].y)==find_set( n*(n+1)+black[j].y)) return true;
    return false;
}
int main(){
    while(scanf("%d%d",&n,&m),n||m){
        black.clear();
        white.clear();
        whs.clear();
        bs.clear();
        int x,y;
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            if(i%2) add_peg(x,y,white,whs);
            else add_peg(x,y,black,bs);
        }
        for(int i=0;i<(n+1)*(n+1);i++) f[i] = i, rk[i] = 0;
        for(int i=0;i<bs.size();i++){
            int x1 = bs[i].p1.x;
            int y1 = bs[i].p1.y;
            int x2 = bs[i].p2.x;
            int y2 = bs[i].p2.y;
            union_set(x1*(n+1)+y1,x2*(n+1)+y2);
        }
        if(check()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
