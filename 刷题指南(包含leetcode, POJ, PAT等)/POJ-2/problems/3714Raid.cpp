#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double INF = 1e20;
const int N = 200005;
struct Point
{
    double x;
    double y;
    int id;
}point[N];
int n;
int tmpt[N];

bool cmpxy(const Point& a, const Point& b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

bool cmpy(const int& a, const int& b)
{
    return point[a].y < point[b].y;
}

double min(double a, double b)
{
    return a < b ? a : b;
}

double dis(int i, int j)
{
    return sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)
                + (point[i].y-point[j].y)*(point[i].y-point[j].y));
}

double Closest_Pair(int left, int right)
{
    double d = INF;
    if(left==right)
        return d;
    if(left + 1 == right){
        if(point[left].id+point[right].id==1)
        return dis(left, right);
        else return INF;
    }
    int mid = (left+right)>>1;
    double d1 = Closest_Pair(left,mid);
    double d2 = Closest_Pair(mid+1,right);
    d = min(d1,d2);
    int i,j,k=0;
    //分离出宽度为d的区间
    for(i = left; i <= right; i++)
    {
        if(fabs(point[mid].x-point[i].x) <= d)
            tmpt[k++] = i;
    }
    sort(tmpt,tmpt+k,cmpy);
    //线性扫描
    for(i = 0; i < k; i++)
    {
        for(j = i+1; j < k && point[tmpt[j]].y-point[tmpt[i]].y<d; j++)
        {
            double d3 = dis(tmpt[i],tmpt[j]);
            if(d > d3 && point[tmpt[i]].id+point[tmpt[j]].id==1)
                d = d3;
        }
    }
    return d;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%lf %lf",&point[i].x,&point[i].y);
            point[i].id=0;
        }
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&point[i+n].x,&point[i+n].y);
            point[i+n].id=1;
        }
        sort(point,point+2*n,cmpxy);
        printf("%.3lf\n",Closest_Pair(0,2*n-1));
    }
    return 0;
}
