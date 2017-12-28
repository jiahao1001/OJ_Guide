#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int N = 1001;
double x,y;
long long X[N],Y[N];
long long g_x,g_y, d_x,d_y;
long long dist2(long long x,long long y){
    return x*x+y*y;
}
bool escape(int i){
    return 4*dist2(g_x-X[i],g_y-Y[i]) <= dist2(d_x-X[i],d_y-Y[i]);
}
int main(){
    int cnt=0;
    scanf("%lf%lf",&x,&y);
    g_x = 1000*x, g_y = 1000*y;
    scanf("%lf%lf",&x,&y);
    d_x = 1000*x, d_y = 1000*y;
    while(scanf("%lf%lf",&x,&y)!=EOF){
        X[cnt] = x*1000;
        Y[cnt] = y*1000;
        cnt++;
    }
    int i=0;
    for(i=0;i<cnt;i++){
        if(escape(i)) break;
    }
    if(i==cnt)printf("The gopher cannot escape.\n");
    else printf("The gopher can escape through the hole at (%.3f,%.3f).\n",X[i]*1.0/1000,Y[i]*1.0/1000);
    return 0;
}
