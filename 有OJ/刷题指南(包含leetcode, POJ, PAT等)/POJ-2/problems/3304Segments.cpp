#include<iostream>
#include<cstdio>
#include<math.h>
#define N 110
#define EPS 1e-10
using namespace std;
typedef struct Node1
{
    double x,y;
}Point;
typedef struct Node2
{
    Point s,t;
}Segment;
Segment s[N];
int n;
double cross(Point o,Point a,Point b)//求叉积 
{
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}
double dis(Point a,Point b) //求两点距离 
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int judge(Point a,Point b)//判定是否与n条线段均相交 
{
    if(dis(a,b)<EPS) return 0;//细节2 
    for(int i=0;i<n;i++)
       if(cross(a,b,s[i].s)*cross(a,b,s[i].t)>EPS)// 精度控制 
          return 0;
    return  1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
          scanf("%lf%lf%lf%lf",&s[i].s.x,&s[i].s.y,&s[i].t.x,&s[i].t.y);
        int yes=0;
        if(n==1) yes=1;//特判 
        for(int i=0;yes==0&&i<n;i++)//枚举线段定点确定的待选直线 
          for(int j=i+1;yes==0&&j<n;j++)
             if(judge(s[i].s,s[j].s)||judge(s[i].s,s[j].t)
             ||judge(s[i].t,s[j].s)||judge(s[i].t,s[j].t))
                yes=1;
        if(yes) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}
