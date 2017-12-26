#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<set>
using namespace std;
int n,t;
set<int> leg;
int coin[50];
int p[4];
int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}
int lcm(){
    int r = 1;
    for(int i=0;i<4;i++){
        r = p[i]/gcd(r,p[i])*r;
    }
    return r;
}
void dfs(int cur,int d){
    if(d==4){
        leg.insert(lcm());
        return;
    }
    for(int i=cur;i<n;i++){
        p[d] = coin[i];
        dfs(i+1,d+1);
    }
}
int main()
{
    while(scanf("%d%d",&n,&t), n||t){
        leg.clear();
        for(int i=0;i<n;i++)
            scanf("%d",coin+i);
        dfs(0,0);
        int x;
        while(t--){
            scanf("%d",&x);
            int sh = INT_MAX, tl = INT_MIN;
            for(set<int>::iterator it=leg.begin();it!=leg.end();it++){
                int y = *it;
                int n = x/y;
                tl = max(tl,n*y);
                sh = min(sh, n*y==x?x:(n+1)*y);
            }
            printf("%d %d\n",tl,sh);
        }
    }
    return 0;
}
