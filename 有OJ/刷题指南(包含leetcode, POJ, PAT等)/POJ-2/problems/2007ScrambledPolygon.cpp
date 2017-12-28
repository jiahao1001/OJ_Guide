#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
using namespace std;
const int N = 50;
struct Point{
    int x,y;
} V[N],P;
int cnt=0;
bool operator<(const Point& p1,const Point& p2){
        return p1.x*p2.y-p2.x*p1.y>0;
}
int main()
{
    int x,y;
    P.x = 10000;
    int id = 0;
    while(scanf("%d%d",&x,&y)!=EOF){
        if(x<P.x) P.x = x, P.y=y,id=cnt;
        else if(x==P.x && y<P.y) P.y = y,id=cnt;
        V[cnt].x = x;
        V[cnt].y = y;
        cnt++;
    }
    for(int i=0;i<cnt;i++) V[i].x-=P.x, V[i].y-=P.y;
    swap(V[0],V[id]);
    sort(V+1,V+cnt);
    for(int i=0;i<cnt;i++) V[i].x+=P.x, V[i].y+=P.y;
    for(int i=0;i<cnt;i++) if(V[i].x==0 && V[i].y==0) id=i;
    for(int i=id;i<cnt;i++){
        printf("(%d,%d)\n",V[i].x,V[i].y);
    }
    for(int i=0;i<id;i++){
        printf("(%d,%d)\n",V[i].x,V[i].y);
    }
    return 0;
}
