#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
int t,x_s,y_s,x_e,y_e;
int x_left,y_top,x_right, y_bottom;
struct Point{
    int x,y;
    Point(int _x,int _y):x(_x),y(_y){}
    Point(){}
};
Point operator-(const Point &p1,const Point &p2){
    Point p(p1.x-p2.x,p1.y-p2.y);
    return p;
}
struct Segment{
    Point p1,p2;
    Segment(Point _p1,Point _p2):p1(_p1),p2(_p2){}
    Segment(){}
};
int cross(const Point &p1,const Point &p2){
    return p1.x*p2.y-p2.x*p1.y;
}
int ccw(const Point &A, const Point& B,const Point& C){
    return cross(B-A,C-B);
}
inline bool inside(int x,int y){
    return (x_left<=x && x<=x_right) && (y_bottom<=y && y<=y_top);
}


inline bool on(Point a,Point b,Point c){
    return   min(b.x,c.x)<=a.x && a.x<=max(b.x,c.x)
        && min(b.y,c.y)<=a.y && a.y<=max(b.y,c.y);
}


bool intersect(Segment s1, Segment s2){
    int d1 = ccw(s1.p1,s1.p2,s2.p1);
    int d2 = ccw(s1.p1,s1.p2,s2.p2);
    int d3 = ccw(s2.p1,s2.p2,s1.p1);
    int d4 = ccw(s2.p1,s2.p2,s1.p2);
    if( (d1>0&&d2<0 || d1<0 && d2>0) && (d3>0&&d4<0 || d3<0 && d4>0))
        return true;
    if(!d1 && on(s2.p1,s1.p1,s1.p2)) return true;
    if(!d2 && on(s2.p2,s1.p1,s1.p2)) return true;
    if(!d3 && on(s1.p1,s2.p1,s2.p2)) return true;
    if(!d4 && on(s1.p2,s2.p1,s2.p2)) return true;
    
    return false;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d%d%d",&x_s,&y_s,&x_e,&y_e,&x_left,&y_top,&x_right,&y_bottom);
        if(x_left>x_right) swap(x_left,x_right);
        if(y_bottom>y_top) swap(y_bottom,y_top);
        //completely inside
        if(inside(x_s,y_s) || inside(x_e,y_e)){
            printf("T\n");
            continue;
        }
        //segment intersect
        Segment v1,v2,h1,h2;
        Segment s  = Segment(Point(x_s,y_s),Point(x_e,y_e));
        v1 = Segment(Point(x_left,y_top),Point(x_left,y_bottom));
        v2 = Segment(Point(x_right,y_top),Point(x_right,y_bottom));
        h1 = Segment(Point(x_left,y_bottom),Point(x_right,y_bottom));
        h2 = Segment(Point(x_left,y_top),Point(x_right,y_top));
        if(intersect(s,v1) || intersect(s,v2) || intersect(s,h1) || intersect(s,h2)) printf("T\n");
        else printf("F\n");
    }
}
