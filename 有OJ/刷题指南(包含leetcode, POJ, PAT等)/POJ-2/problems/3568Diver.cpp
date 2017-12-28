#include<math.h>
#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
#include<set>
#include<float.h>
#include<queue>
using namespace std;
const int N = 20;
const double EPS = 1e-7;
int d,vd,n,r,w,vs;
int di[N],wi[N],fi[N];
struct Point{
    double x,y;
    Point(double _x,double _y):x(_x),y(_y){}
    Point(){}
};
bool operator<(const Point& p1,const Point& p2){
    if(p1.x==p2.x) return p1.y<p2.y;
    else return p1.x<p2.x;
}
struct Circle{
    double x,y;
    set<Point> kp;
    Circle(double _x,double _y):x(_x),y(_y){}
    Circle(){}
};
vector<Circle> circles;
set<Point> s;
queue<Point> q;
map<Point,set<Point> > g;
double sx,sy,v;
void addEdge(Point p1,Point p2){
    g[p1].insert(p2);
    g[p2];
}

int dblcmp(double a,double b){
    return a<b-EPS?-1:a>b+EPS?1:0;
}
bool between(double a,double b,double c){
    if(dblcmp(b,c)>0) swap(b,c);
    return dblcmp(a,b)>=0 && dblcmp(a,c)<=0;
}
bool okD(double d) {
    return dblcmp(d, r) >= 0;
}
inline double sqr(double x){
    return x*x;
}
bool okWrt(double x, double y, Circle u) {
    return okD(sqrt(sqr(x - u.x) + sqr(y - u.y)));
}

bool okPoint(double x, double y) {
    if (dblcmp(x, 0) < 0 || dblcmp(x, 2 * w) > 0 || dblcmp(y, 0) < 0 || dblcmp(y, d) > 0)
        return false;
    for(int i=0;i<circles.size();i++)
        if (!okWrt(x, y, circles[i]))
            return false;
    return true;
}

bool okLine(double x1, double y1, double x2, double y2) {
    if (!okPoint(x1, y1) || !okPoint(x2, y2))
        return false;
    double a = y1 - y2;
    double b = x2 - x1;
    double len = sqrt(sqr(a) + sqr(b));
    if (len < EPS)
        return true;
    a /= len;
    b /= len;
    double c = a * x1 + b * y1;
    for (int i=0;i< circles.size();i++) {
        Circle & u =circles[i];
        double d0 = a * u.x + b * u.y - c;
        if (!okD(fabs(d0))) {
            double x0 = u.x - d0 * a;
            double y0 = u.y - d0 * b;
            if (between(x0, x1, x2) && between(y0, y1, y2))
                return false;
        }
    }
    return true;
}

	// only works for segments going around the top of the circle u
bool okSeg(double x1, double y1, double x2, double y2, Circle u) {
    if (!okPoint(x1, y1) || !okPoint(x2, y2))
        return false;
    // check intersection with circles
    for (int i =0;i< circles.size(); i++) {
        Circle &t = circles[i];
        double vx = t.x - u.x;
        double vy = t.y - u.y;
        double len = sqrt(sqr(vx) + sqr(vy));
        if (dblcmp(len, 2 * r) < 0) {
            double x3 = u.x + vx / 2;
            double y3 = u.y + vy / 2;
            if (dblcmp(y3, u.y) > 0 && between(x3, x1, x2))
                return false;
        }
    }
    // make sure there's no "deep dive" on this segment
    if (dblcmp(x1, u.x) <= 0 && dblcmp(x2, u.x) >= 0 && dblcmp(u.y + r, d) > 0)
        return false;
    return true;
}
void addLine(double x1, double y1, double x2, double y2) {
    if (okLine(x1, y1, x2, y2))
        addEdge(Point(x1,y1),Point(x2,y2));
}

void addCurve(double x1, double y1, Circle u) {
    // y = a1 - v * x;
    double a1 = y1 + v * x1;
    
    // y = a3 + v * x;
    double x3 = u.x - sx;
    double y3 = u.y + sy;
    double a3 = y3 - v * x3;
    
    // a1 - v * x = a3 + v * x
    double x2 = (a1 - a3) / (2 * v);
    double y2 = a1 - v * x2;
    
    // outside hit?
    if (dblcmp(x1, x2) <= 0 && dblcmp(x2, x3) <= 0 &&
        okLine(x1, y1, x2, y2) && okLine(x2, y2, x3, y3))
        for (set<Point>::iterator it = u.kp.begin();it!=u.kp.end();it++){
            const Point &p4 = *it;
            if (dblcmp(x3, p4.x) <= 0 && okSeg(x3, y3, p4.x, p4.y, u))
                addEdge(Point(x1,y1),p4);
        }
    
    if (dblcmp(x2, x3) >= 0) {
        // hit top segment; intersect y = a1 - v * x with u circle
        double xn = v;
        double yn = 1;
        double cn = a1;
        double len = sqrt(sqr(xn) + sqr(yn));
        xn /= len;
        yn /= len;
        cn /= len;
        double dn = cn - xn * u.x - yn * u.y;
        double dt = sqrt(sqr(r) - sqr(dn));
        
        double x5 = u.x + dn * xn - dt * yn;
        double y5 = u.y + dn * yn + dt * xn;
        
        if (dblcmp(x1, x5) <= 0 && okLine(x1, y1, x5, y5))
            for (set<Point>::iterator it = u.kp.begin();it!=u.kp.end();it++){
                Point p4 = *it;
                if (dblcmp(x5, p4.x) < 0 && okSeg(x5, y5, p4.x, p4.y, u))
                    addEdge(Point(x1,y1),p4);
            }
    }
}
void addFrom(double x, double y) {
    if (!okPoint(x, y))
        return;
    addLine(x, y, 2 * w, y - v * (2 * w - x));
    addLine(x, y, x + y / v, 0);
    addLine(0, y + v * x, x, y);
    for(int i=0;i<circles.size();i++)
        addCurve(x,y,circles[i]);
}





int main()
{
    scanf("%d%d%d%d%d%d",&d,&vd,&n,&r,&w,&vs);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",di+i,wi+i,fi+i);
    for(int i=0;i<n;i++){
        int x = fi[i]==-1?wi[i]:2*w-wi[i];
        int y = di[i];
        circles.push_back(Circle(x,y));
        if(x<r) circles.push_back(Circle(x+2*w,y));
        if(x>2*w-r) circles.push_back(Circle(x-2*w,y));
    }
    //for(int i=0;i<circles.size();i++)
    //    printf("Circle %f %f\n",circles[i].x, circles[i].y);
    v = (double)vd/vs;
    sx = r*v/sqrt(1.0+v*v);
    sy = sqrt(1.0*r*r - sx*sx);
    for(int i=0;i<circles.size();i++){
        Circle &u = circles[i];
        double x = u.x + sx;
        double y = u.y + sy;
        //trim to right
        if(dblcmp(x,2*w)>0) x = 2*w, y = u.y + sqrt(1.0*r*r-(2*w-u.x)*(2*w-u.x));
        for(int j=0;j<circles.size();j++){
            Circle &v  = circles[j];
            if(!okWrt(x,y,v)){
                double vx = v.x - u.x;
                double vy = v.y - u.y;
                double len = sqrt(vx*vx + vy*vy);
                vx /= len, vy/=len, len/=2;
                double off = sqrt(1.0*r*r-len*len);
                double x1 = u.x + vx*len - vy*off;
                double y1 = u.y + vy*len + vx*off;
                if(between(x1,u.x-sx,x)) x = x1, y = y1;
            }
        }
        if(okPoint(x,y)) u.kp.insert(Point(x,y));//,printf("Trimmed %f %f\n",x,y);
        for(int j=0;j<circles.size();j++){
            Circle &t = circles[j];
            double x0 = t.x -sx, y0 = t.y+sy, a= -v, b=1;
            double c = a*x0 + b*y0;
            double len = sqrt(a*a+b*b);
            a/=len,b/=len,c/=len;
            double dn = a*u.x + b*u.y - c;
            if(fabs(dn)<r-EPS) {
                double dt = sqrt(1.0*r*r- dn*dn);
                double x1 = u.x - dn*a + dt*b;
                double y1 = u.y - dn*b - dt*a;
                if(between(x1,u.x-sx,u.x+sx) && okPoint(x1,y1)) u.kp.insert(Point(x1,y1));
            }
        }
    }
    for(int i=0;i<circles.size();i++){
        Circle &u = circles[i];
        for(set<Point>::iterator it = u.kp.begin();it!=u.kp.end();it++)
            //printf("[%.10f, %.10f]\n",it->x,it->y),
            addFrom(it->x,it->y);
    }
    double dmin = d;
    double result = DBL_MAX;
    for(int cycle = 0;;cycle++){
        addFrom(0,dmin);
        s.clear();
        while(!q.empty()) q.pop();
        for(map<Point,set<Point> >::iterator it = g.begin();it!=g.end();it++){
            if(dblcmp(it->first.x,0)==0 && dblcmp(it->first.y,dmin)>=0) s.insert(it->first), q.push(it->first);
        }
        double newdmin = dmin;
        
        
        while(!q.empty()){
            Point p = q.front();
            q.pop();
            if(dblcmp(p.x, 2*w)==0) newdmin = min(newdmin,p.y);
            if(dblcmp(p.y,0) ==0 ) result = min(result,p.x+cycle*2*w);
            set<Point> &pts = g[p];
            for(set<Point>::iterator it = pts.begin();it!=pts.end();it++){
                if(!s.count(*it)) s.insert(*it), q.push(*it);
            }
        }
        if(result < DBL_MAX) break;
        if(dblcmp(newdmin,dmin) == 0) break;
        dmin = newdmin;
    }
    if(result < DBL_MAX) printf("%.15f\n",result/vs);
    else printf("IMPOSSIBLE\n");
    return 0;
}
