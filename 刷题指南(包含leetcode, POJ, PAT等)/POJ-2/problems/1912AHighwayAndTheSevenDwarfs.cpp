#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
struct Point{
    double x,y;
};
bool operator<(const Point&p1 ,const Point& p2){
    if(p1.x==p2.x) return p1.y<p2.y;
    else return p1.x<p2.x;
}
Point operator-(const Point& p1,const Point &p2){
    Point p;
    p.x = p1.x-p2.x;
    p.y = p1.y-p2.y;
    return p;
}
double cross(const Point& p1,const Point &p2){
    return p1.x*p2.y-p2.x*p1.y;
}
Point hs[100000];
Point ls[100000];
Point us[100000];
double d1[100000],d2[100000];
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%lf %lf",&hs[i].x,&hs[i].y);
    sort(hs,hs+N);
    int k1=0,k2=0;
    for(int i=0;i<N;i++){
        while(k1>=2 && cross(hs[i]-ls[k1-2],hs[i]-ls[k1-1])<=0)
              k1--;
        ls[k1++] = hs[i];
    }
    us[k2++] = ls[k1-1];
    for(int i=N-2;i>=0;i--){
        while(k2>=2 && cross(hs[i]-us[k2-2],hs[i]-us[k2-1])<=0)
            k2--;
        us[k2++] = hs[i];
    }
    for(int i=0;i<k1-1;i++){
        Point p = ls[i+1]-ls[i];
        d1[i] = p.y/p.x;
    }
    for(int i=0;i<k2-1;i++){
        Point p = us[i+1]-us[i];
        d2[i] = p.y/p.x;
    }
    double x1,y1,x2,y2;
    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF){
        double d = (y2-y1)/(x2-x1);
        int i = lower_bound(d1,d1+k1-1,d)-d1;
        int j = lower_bound(d2,d2+k2-1,d)-d2;
        Point p,q;
        p.x = x1, p.y = y1;
        q.x = x2, q.y = y2;
        if(cross(ls[i]-p,q-p)*cross(us[j]-p,q-p)<0) printf("BAD\n");
        else printf("GOOD\n");
        
    }
    
    return 0;
}
