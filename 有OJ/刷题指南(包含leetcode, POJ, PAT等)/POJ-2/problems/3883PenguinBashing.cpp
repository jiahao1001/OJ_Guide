#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
const double PI = acos(-1.0);
const double g = 9.81;
const double v = 25;
const int N = int(1e5);
const double EPS = 1e-8;
double falling_time(double alpha)
{
    //a is radian
    double a = g/2, b = -v*sin(alpha), c = -1;
    return (-b+sqrt(b*b-4*a*c))/2/a;
}
int n;
char obstacle_type[N]; //'m' or 's'
double spike[N], mine[N];
double obstacle[N];
int s_cnt, m_cnt;
double travel(double d,double hv){
    double nd = 0;
    for(int next=0;next<n;next++){
        nd = obstacle[next];
        if(nd<d) continue;
        if(nd-d>hv/5.0) {
            //stop before next obstacle
            break;
        }
        if(obstacle_type[next]=='s') return -1;
        hv-=(nd-d)*5.0;;
        hv+=4.0;
        d = nd+2.0;
        
    }
    return d+hv/5.0;
}
int main()
{
    int kk;
    double x;
    char s[20];
    scanf("%d",&kk);
    while(kk--){
        s_cnt = 0, m_cnt = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lf %s",&x,s);
            if(!strcmp(s,"spike")) spike[s_cnt++] = x;
            else mine[m_cnt++] = x;
        }
        sort(spike,spike+s_cnt);
        sort(mine,mine+m_cnt);
        //merge
        int i = 0, j = 0;
        int k = 0;
        while(i<s_cnt && j<m_cnt){
            if(spike[i]<mine[j]) obstacle[k] = spike[i++], obstacle_type[k++] = 's';
            else obstacle[k] = mine[j++], obstacle_type[k++] = 'm';
        }
        while(i<s_cnt) obstacle[k] = spike[i++],obstacle_type[k++] = 's';
        while(j<m_cnt) obstacle[k] = mine[j++], obstacle_type[k++] = 'm';
        
        double best = -100;
        int angle = -90;
        for(int a = -90;a<=90;a++){
            double alpha = PI*a/180.0;
            double fall_t = falling_time(alpha);
            double fall_v = v*cos(alpha);
            double fall_x = fall_v*fall_t;
            double dist = travel(fall_x,fall_v);
            //if(a==34) cout<<fall_x<<" "<<fall_v<<endl;
            if(dist>best+EPS) best = dist, angle = a;
        }
        //printf("%d\n",(int)round(-1.0*100));
        printf("%d %d\n",(int)round(best*100),angle);
    }
    return 0;
}
