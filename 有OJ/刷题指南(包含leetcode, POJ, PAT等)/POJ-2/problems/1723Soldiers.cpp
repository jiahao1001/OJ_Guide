#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
#include<stdlib.h>
using namespace std;
const int N = 10001;
int x[N],y[N];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",x+i,y+i);
    sort(y,y+n);
    int midy = y[n/2];
    int total = 0;
    for(int i=0;i<n;i++) total+=abs(y[i]-midy);
    sort(x,x+n);
    for(int i=0;i<n;i++) x[i]-=i;
    sort(x,x+n);
    int midx = x[n/2];
    for(int i=0;i<n;i++) total += abs(x[i]-midx);
    printf("%d\n",total);
    
    
    return 0;
}
