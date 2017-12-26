#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int n;
double x,y,lx,ly,cx,cy;
int main()
{
    while(scanf("%d",&n)!=EOF){
        printf("%d",n);
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&cx,&cy);
            if(i==0)x=cx,y = cy,lx=cx,ly=cy;
            else if(i==n-1){
                printf(" %.6f %.6f",(cx+lx)/2,(cy+ly)/2);
                printf(" %.6f %.6f\n",(cx+x)/2,(cy+y)/2);
            }else{
                printf(" %.6f %.6f",(cx+lx)/2,(cy+ly)/2);
                lx = cx, ly = cy;
            }
        }
    }
    return 0;
}

