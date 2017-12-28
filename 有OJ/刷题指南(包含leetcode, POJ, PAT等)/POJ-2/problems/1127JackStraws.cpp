#include<iostream>
#include<stdio.h>
using namespace std;
struct Point{
    int x,y;
    Point(int _x,int _y):x(_x),y(_y){};
    Point(){}
};
Point  operator-(const Point &p1,const Point &p2){
    return Point(p1.x-p2.x,p1.y-p2.y);
}
int cross(const Point &p1,const Point &p2){
    return p1.x*p2.y-p2.x*p1.y;
}
int ccw(const Point &A,const Point &B,const Point &C){
    return cross(B-A,C-B);
}
struct Seg{
    Point p1,p2;
    Seg(){};
    Seg(int x1,int y1,int x2,int y2){
        p1=Point(x1,y1);
        p2=Point(x2,y2);
        if(p1.x>p2.x) swap(p1,p2);
    }
} segs[13];
int g[13][13];
int n;
int a,b;
bool between(int x,int x1,int x2){
    return x1<=x && x<=x2;
}
bool intersect(const Seg &s1,const Seg &s2){
    if(cross(s1.p1-s1.p2,s2.p1-s2.p2)==0){
        //collinear
        if(ccw(s1.p1,s1.p2,s2.p1)) return false;
        if(s1.p1.x == s1.p2.x){
            int y1 = min(s1.p1.y,s1.p2.y);
            int y2 = max(s1.p1.y,s1.p2.y);
            int Y1 = min(s2.p1.y,s2.p2.y);
            int Y2 = max(s2.p1.y,s2.p2.y);
            return between(y1,Y1,Y2) || between(Y1,y1,y2);
        }
        
        return between(s1.p1.x,s2.p1.x,s2.p2.x) || between(s2.p1.x, s1.p1.x, s1.p2.x); 
    }
    return ccw(s1.p1,s2.p1,s2.p2)*ccw(s1.p2,s2.p1,s2.p2)<=0 && ccw(s2.p1,s1.p1,s1.p2)*ccw(s2.p2,s1.p1,s1.p2)<=0;
}
int main()
{
    int x1,y1,x2,y2;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            segs[i] = Seg(x1,y1,x2,y2);
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i==j || intersect(segs[i],segs[j])) g[i][j]=1;
                else g[i][j]=0;
            
        //floyd
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(g[i][k]&&g[k][j]) g[i][j]=1;
        
        while(scanf("%d%d",&a,&b),a||b)
        {
            a--,b--;
            if(g[a][b]) printf("CONNECTED\n");
            else printf("NOT CONNECTED\n");
        }
        
        
    }
    return 0;
}
