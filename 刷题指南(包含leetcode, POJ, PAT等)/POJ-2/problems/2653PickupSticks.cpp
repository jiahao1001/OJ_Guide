#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
const int N = 100001;
const double eps = 1e-8;
struct Point{
    double x,y;
    Point(double _x,double _y):x(_x),y(_y){};
    Point(){}
};
Point  operator-(const Point &p1,const Point &p2){
    return Point(p1.x-p2.x,p1.y-p2.y);
}
double cross(const Point &p1,const Point &p2){
    return p1.x*p2.y-p2.x*p1.y;
}
double ccw(const Point &A,const Point &B,const Point &C){
    return cross(B-A,C-B);
}
struct Seg{
    
    Point p1,p2;
    Seg(){};
    Seg(double x1,double y1,double x2,double y2){
        p1=Point(x1,y1);
        p2=Point(x2,y2);
        //if(p1.x>p2.x) swap(p1,p2);
    }
} seg[N];
int n;

bool intersect(const Seg &s1,const Seg &s2){
    return ccw(s1.p1,s2.p1,s2.p2)*ccw(s1.p2,s2.p1,s2.p2)<=-eps && ccw(s2.p1,s1.p1,s1.p2)*ccw(s2.p2,s1.p1,s1.p2)<=-eps;
}
int main()
{
    double x1,y1,x2,y2;
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            seg[i] = Seg(x1,y1,x2,y2);
        }
        printf("Top sticks:");
        bool first = true;
        for(int i=1;i<=n;i++){
            bool bad = false;
            for(int j=i+1;j<=n;j++)
                if(intersect(seg[i],seg[j])){
                    bad = true;
                    break;
                }
            if(bad) continue;
            if(first){
                first = false;
                printf(" %d",i);
            }else{
                printf(", %d",i);
            }
        }
        printf(".\n");
        
    }
    return 0;
}
