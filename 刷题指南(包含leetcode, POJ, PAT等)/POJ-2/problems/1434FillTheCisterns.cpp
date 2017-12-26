#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
#include<math.h>
using namespace std;
const int N = 50000;
const double eps = 1e-6;
int k,n;
int b[N],h[N],w[N],d[N];
int V;
inline bool check(double lv){
    //<=V
    double v = 0.0;
    for(int i=0;i<n;i++){
        if(lv<=b[i]) v += 0.0;
        else if(lv<=b[i]+h[i]) v+= (lv-b[i])*w[i]*d[i];
        else v += h[i]*w[i]*d[i];
    }
    return v>=V;
}

int main()
{
    double r = 0;
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        double total = 0;
        for(int i=0;i<n;i++)
            scanf("%d%d%d%d",b+i,h+i,w+i,d+i), total+= h[i]*w[i]*d[i], r = max(r,1.0*b[i]+h[i]);
        scanf("%d",&V);
        if(total<V) {
            printf("OVERFLOW\n");
            continue;
        }
        double l = 0;
        double mid;
        while(fabs(l-r)>eps){
            mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%.2f\n",l);
        
    }
    return 0;
}
