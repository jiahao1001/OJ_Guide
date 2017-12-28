
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
struct Point{
    int id;
    int x,y;
    int len2(){
        return x*x+y*y;
    }
};
Point operator-(const Point &p1, const Point &p2){
    Point p;
    p.x = p1.x-p2.x;
    p.y = p1.y-p2.y;
    return p;
}
int cross(Point p1,Point p2){
    return p1.x*p2.y-p2.x*p1.y;
}
Point cur;
bool cmp(const Point &p1, const Point &p2){
    int c = cross(p1-cur,p2-cur);
    if(c==0) return (p1-cur).len2()<(p2-cur).len2();
    return c>0;
}
Point plant[51];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int a,x,y;
        int ly = 10000;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a,&x,&y);
            plant[i].id = a;
            plant[i].x = x;
            plant[i].y = y;
            ly = min(ly,y);
        }
        plant[0].id = 0;
        plant[0].x = 0;
        plant[0].y = ly;
        cur = plant[0];
        for(int i=1;i<=n;i++){
            sort(plant+i,plant+n+1,cmp);
            cur=plant[i];
        }
        printf("%d",n);
        for(int i=1;i<=n;i++)
            printf(" %d",plant[i].id);
        printf("\n");
    }
    return 0;
}
