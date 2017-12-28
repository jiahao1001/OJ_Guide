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
typedef pair<int,int> PII;
int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}
const int N = 1000;
int n;
int X[N],Y[N];
PII slope[N];
int main()
{
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%d%d",X+i,Y+i);
        
        int best = 0;
        for(int i=0;i<n;i++){
            int lm = 0;
            
            for(int j=0;j<n;j++){
                int dx = X[j]-X[i], dy = Y[j]-Y[i];
                int g = gcd(dx,dy);
                if(g==0) slope[j] = make_pair(0,0);
                else
                    slope[j] = make_pair(dx/g,dy/g);
            }
            int cnt = 0;
            sort(slope,slope+n);
            PII last = make_pair(-1,-1);
            for(int j =0;j<n;j++){
                if(slope[j]!=last){
                    lm = max(lm,cnt);
                    cnt = 1;
                    last = slope[j];
                }else cnt++;
            }
            lm = max(lm,cnt);
            best = max(best,lm+1);
            
        }
        printf("%d\n",best);
    }
    return 0;
    
}
