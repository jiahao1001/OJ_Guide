#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
using namespace std;
const int inf = INT_MAX/2;
const int N = 501;
int d[N][N];
int e[N][N];
int n,m;
int main()
{
    int a,b,c;
    int q=1;
    while(scanf("%d%d",&n,&m),n){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) d[i][j] = e[i][j] = inf;
        for(int i=1;i<=n;i++) d[i][i] = e[i][i] = 0;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            d[a][b] = c;
            d[b][a] = c;
            e[a][b] = c;
            e[b][a] = c;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
        printf("System #%d\n",q++);
        if(m==0){
            printf("The last domino falls after 0.0 seconds, at key domino 1.\n\n");
            continue;
        }
        bool ed = true;
        double best = 0;
        int a,b;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                if(e[i][j]==inf) continue;
                if(e[i][j]==abs(d[1][i]-d[1][j])){
                    int x = i;
                    int l = d[1][i];
                    if(d[1][j]>d[1][i]) x=j,l = d[1][j];
                    if(l>best) best = l, ed = true, b = x;
                    //end
                }else{
                    double l = (e[i][j]-abs(d[1][i]-d[1][j]))/2.0+ max(d[1][i],d[1][j]);
                    if(l>best) best = l , ed =false, a=i,b=j;
                }
            }
        if(ed) printf("The last domino falls after %.1f seconds, at key domino %d.",best,b);
        else printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.",best,a,b);
        printf("\n\n");
    }
    return 0;
}
