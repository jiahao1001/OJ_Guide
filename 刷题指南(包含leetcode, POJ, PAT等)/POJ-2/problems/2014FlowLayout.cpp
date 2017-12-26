#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
int width;
int W,H;

int main()
{
    int w,h;
    while(scanf("%d",&width),width){
        W = 0, H = 0;
        int l_w = 0;
        int l_h = 0;
        while(scanf("%d%d",&w,&h), w!=-1){
            if(l_w+w<=width) l_w+=w,l_h = max(l_h,h);
            else W=max(W,l_w), l_w=w, H+=l_h, l_h = h;
        }
        H+=l_h, W=max(W,l_w);
        printf("%d x %d\n",W,H);
    }
    return 0;
}
