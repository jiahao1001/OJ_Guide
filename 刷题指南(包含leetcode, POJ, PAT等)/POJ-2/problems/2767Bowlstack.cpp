#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
struct Bowl{
    double h,r,R;
}bowls[9];
double offset(const Bowl& b1,const Bowl& b2){
    //stack b2 on b1
    if(b2.r>=b1.R) return b1.h;
    double h = b1.h/(b1.R-b1.r)*(b2.r-b1.r);
    if(b1.R>=b2.R) h = max(b1.h/(b1.R-b1.r)*(b2.R-b1.r)-b2.h,h);
    else h = max(h,b1.h-b2.h/(b2.R-b2.r)*(b1.R-b2.r));
    return max(0.0,h);
}
int n;
double best;
int v[9];
double height[9];
double stack_bowl(){
    double h = 0;
    height[0] = 0;
    for(int i=1;i<n;i++){
        int b1,b2;
        b2 = v[i];
        height[i] = 0;
        for(int j=0;j<i;j++){
            b1 = v[j];
            height[i]=max(height[i],height[j]+offset(bowls[b1],bowls[b2]));
        }
    }
    for(int i=0;i<n;i++) h = max(h,height[i]+bowls[v[i]].h);
    return h;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&bowls[i].h,&bowls[i].r,&bowls[i].R);
        for(int i=0;i<n;i++)
            v[i] = i;
        best = 999999999;
        do{
            best = min(best,stack_bowl());
        }while(next_permutation(v,v+n));
        printf("%d\n",(int)best);
    }
    return 0;
}
