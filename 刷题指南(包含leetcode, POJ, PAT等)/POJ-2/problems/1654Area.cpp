#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
#include<sstream>
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<numeric>
#include<map>
int x[1000010], y[1000010];
char s[1000010];
int dx[9]={-1,0,1,-1,0,1,-1,0,1};
int dy[9]={-1,-1,-1,0,0,0,1,1,1};
int n;
using namespace std;
long long ccw(int i,int j,int k){
    long long x1,y1,x2,y2;
    x1 = x[j]-x[i], y1=y[j]-y[i];
    x2 = x[k]-x[j], y2=y[k]-y[j];
    return x1*y2-x2*y1;
}
long long area(){
    long long S=0;
    //x[n] = y[n] = 0;
    for(int i=0;i<n-1;i++){
        S+=ccw(0,i,i+1);
    }
    return S;
}
int main(){
    int t;
    long long cx,cy;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        n = strlen(s);
        cx = cy = 0;
        x[0] = y[0] = 0;
        for(int i=0;i<n-1;i++){
            cx += dx[s[i]-'1'], cy+=dy[s[i]-'1'];
            x[i+1] = cx;
            y[i+1] = cy;
        }
        long long ans = area();
        if(ans<0) ans=-ans;
        if(ans%2) printf("%lld.5\n",ans/2);
        else printf("%lld\n",ans/2);
    }
    return 0;
}
