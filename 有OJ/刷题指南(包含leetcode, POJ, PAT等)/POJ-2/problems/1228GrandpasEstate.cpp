#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;
struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
};
Point operator-(const Point& p1, const Point &p2){
    return Point(p1.x-p2.x,p1.y-p2.y);
}
inline int cross(Point p1,Point p2){
    return p1.x*p2.y-p2.x*p1.y;
}
bool operator<(const Point &p1,const Point& p2){
    if(p1.y==p2.y) return p1.x<p2.x;
    return p1.y<p2.y;
}
int t,n;
Point spike[1010];
Point convex[2020];
int top;
void granham()
{
    top = 0;
    convex[top++] = spike[0];
    convex[top++] = spike[1];
    for(int i=2;i<n;i++){
        while(top>=2 && cross(convex[top-1]-convex[top-2],spike[i]-convex[top-1])<0) top--;
        convex[top++] = spike[i];
    }
    int len = top;
    for(int i=n-2;i>=0;i--){
        while(top>len && cross(convex[top-1]-convex[top-2],spike[i]-convex[top-1])<0) top--;
        convex[top++] = spike[i];
    }
    top--;
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        
        for(int i=0;i<n;i++){
            scanf("%d%d",&spike[i].x, &spike[i].y);
            
        }
        if(n<=5){
            printf("NO\n");
            continue;
        }
        sort(spike,spike+n);
        granham();//compute convex hull in convex
        int cnt = 0;
        convex[top]=convex[0];
        Point dir = convex[1]-convex[0];
        cnt = 2;
        bool ok = true;
        for(int i=2;i<=top;i++){
            Point ndir = convex[i]-convex[i-1];
            if(cross(dir,ndir)==0) cnt++; // collinear
            else{
                if(cnt<3){
                    ok = false;
                    break;
                }
                dir = ndir, cnt = 2;
            }
            
        }
        if(cnt<3 || cnt >= n ) ok = false;
        if(ok) printf("YES\n");
        else printf("NO\n");
        
    }
    return 0;
}
