#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
const int INF = INT_MAX/2;
int g[11][11];
int n;
int A[11];
int main()
{
    while(scanf("%d",&n),n){
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++) scanf("%d",&g[i][j]);
        for(int k=0;k<=n;k++)
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
        for(int i=0;i<n;i++)
            A[i] = i+1;
        int best = INF;
        do{
            int d = 0;
            int u=0;
            for(int i=0;i<n;i++)
                d+=g[u][A[i]], u = A[i];
            d+=g[u][0];
            best = min(best,d);
        }while(next_permutation(A,A+n));
        printf("%d\n",best);
    }
    return 0;
}
