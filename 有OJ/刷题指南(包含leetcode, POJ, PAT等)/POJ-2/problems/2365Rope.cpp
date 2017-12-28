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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
#include <math.h>
#include <queue>
using namespace std;
double PI = acos(-1.0);
double x[100],y[100];
inline double dist(double x,double y){
    return sqrt(x*x+y*y);
}
int main(){
    int n;
    double r;
    scanf("%d%lf",&n,&r);
    for(int i=0;i<n;i++)
        scanf("%lf%lf",x+i,y+i);
    double total = 0;
    for(int i=0;i<n;i++){
        total += dist(x[(i+1)%n]-x[i],y[(i+1)%n]-y[i]);
    }
    printf("%.2f\n",total+2*PI*r);
    return 0;
}
