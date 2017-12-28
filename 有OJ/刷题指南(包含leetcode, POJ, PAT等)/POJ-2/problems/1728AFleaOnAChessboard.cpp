#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<utility>
#include<set>
using namespace std;
#define MP make_pair
typedef pair<pair<int,int>,pair<int,int> > pipi;
int S,x,y,dx,dy;
void print()
{
    printf("The flea cannot escape from black squares.\n");
}
int main()
{
    while(scanf("%d%d%d%d%d",&S,&x,&y,&dx,&dy),S){
        set<pipi> v;
        // a x b y
        int a = x/S;
        int b = y/S;
        a%=2,b%=2;
        int xx = x, yy = y;
        x%=S,y%=S;
        int cnt = 0;
        bool ok =true;
        while(true){
            pipi p = MP(MP(a,x),MP(b,y));
            if(v.count(p)){
                ok = false;
                break;
            }
            v.insert(p);
            if(a+b==1 && x && y) break;
            cnt++;
            x+=dx, y+=dy;
            a+=x/S,b+=y/S;
            x%=S,y%=S;
            a%=2,b%=2;
            xx+=dx,yy+=dy;
        }
        if(ok)
            printf("After %d jumps the flea lands at (%d, %d).\n",cnt,xx,yy);
        else print();
              
       

    }
    return 0;
}
