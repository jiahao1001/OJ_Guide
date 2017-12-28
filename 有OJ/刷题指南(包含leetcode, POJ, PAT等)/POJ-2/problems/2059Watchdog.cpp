
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdio.h>
using namespace std;
int H;
pair<int,int> hs[50];
inline double dis(double x,double y){
    return sqrt(x*x+y*y);
}
inline bool fall(int x,int y,int d){
    for(int i=0;i<H;i++){
        if(dis(x-hs[i].first, y-hs[i].second)>d || make_pair(x,y)==hs[i]) return true;
    }
    return false;
}
int main(){
    int t,S;
    scanf("%d",&t);
    while(t--){
        bool poodle = true;
        int X,Y;
        scanf("%d%d",&S,&H);
        for(int i=0;i<H;i++){
            scanf("%d%d",&X,&Y);
            hs[i] = make_pair(X,Y);
        }
        for(int x=0;x<=S;x++)
            for(int y=0;y<=S;y++){
                int d = min(min(x,y),min(S-x,S-y));
                if(!fall(x,y,d)) {
                    poodle = false;
                    X=x,Y=y;
                    goto A;
                }
            }
    A:  if(poodle) printf("poodle\n");
        else printf("%d %d\n",X,Y);
    }
    return 0;
}
