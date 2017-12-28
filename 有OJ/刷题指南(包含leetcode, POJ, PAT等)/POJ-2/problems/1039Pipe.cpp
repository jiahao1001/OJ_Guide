#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
#include <math.h>
using namespace std;
const double eps = 1e-8;
struct Point{
    double x,y;
} a[22],b[22];
struct Line{
    double a,b,c;
};
int n;
double ans;
Point operator-(const Point &A, const Point &B){
    Point C;
    C.x = A.x-B.x;
    C.y = A.y-B.y;
    return C;
}
double cross(const Point &A, const Point &B){
    return A.x*B.y-B.x*A.y;
}
double ccw(const Point &A, const Point &B, const Point &C){
    return cross(B-A,C-B);
}

Line getLine(Point p1,Point p2){
    Line l;
    l.a = p1.y-p2.y;
    l.b = p2.x-p1.x;
    l.c = p1.x*p2.y-p2.x*p1.y;
    return l;
}
bool fun(Point p1, Point p2, int e){
    int i, sign;
    for(i = 0; i < n-1; i ++){
        if(ccw(p1,p2, a[i]) < -eps || ccw(p1, p2, a[i+1]) < -eps){
            sign = 1; break;
        }
        if(ccw(p1,p2, b[i]) > eps || ccw(p1, p2, b[i+1]) > eps){
            sign = 2; break;
        }
    }
    if(i == n-1) return true;   // Through all the pipe.
    if(i < e) return false;     
    Line l1, l2;                
    l1 = getLine(p1, p2);
    if(sign == 1) l2 = getLine(a[i], a[i+1]);
    else l2 = getLine(b[i], b[i+1]);
    ans = max(ans, (l1.b*l2.c-l2.b*l1.c)/(l1.a*l2.b-l2.a*l1.b));
    return false;
}

int main(){
    int i, j;
    while(scanf("%d", &n) && n != 0){
        for(i = 0; i < n; i ++){
            scanf("%lf%lf", &a[i].x, &a[i].y);
            b[i].x = a[i].x;
            b[i].y = a[i].y - 1;
        }
        ans = -99999999;
        bool flag = false;
        if(n < 3) flag = true;
        for(i = 0; i < n && !flag; i ++)
            for(j = i + 1; j < n; j ++){
                flag = fun(a[i], b[j], j);
                if(flag) break;
                flag = fun(b[i], a[j], j);
                if(flag) break;
            }
        if(flag) printf("Through all the pipe.\n");
        else printf("%.2f\n", ans);
    }
    return 0;
}
