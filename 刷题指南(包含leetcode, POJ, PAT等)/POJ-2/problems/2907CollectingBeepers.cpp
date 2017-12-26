#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<algorithm>

using namespace std;

int n,m,k;
int start;
int beeper[10];
int dist[400][400];
int main()
{
    int t;
    scanf("%d",&t);
    int x,y;
    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%d%d",&x,&y);
        x--,y--;
        start = x*m+y;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            x--,y--;
            beeper[i] = x*m+y;
        }
        sort(beeper,beeper+k);
        for(int i=0;i<n*m;i++)
            for(int j=0;j<n*m;j++) dist[i][j] = INT_MAX/2;
        for(int i=0;i<n*m;i++) dist[i][i] = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                int a = i*m+j;
                int b;
                if(j+1<m){
                    b = i*m+j+1;
                    dist[a][b] = dist[b][a] = 1;
                }
                if(i+1<n){
                    b = i*m+m+j;
                    dist[a][b] = dist[b][a] = 1;
                }
            }
        int best = INT_MAX;
        for(int k=0;k<n*m;k++)
            for(int i=0;i<n*m;i++)
                for(int j=0;j<n*m;j++)
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        do{
            int tot = dist[start][beeper[0]];
            for(int i=1;i<k;i++)
                tot += dist[beeper[i-1]][beeper[i]];
            tot += dist[beeper[k-1]][start];
            //printf(" -- %d\n",tot);
            best = min(best,tot);
        }while(next_permutation(beeper,beeper+k));
        printf("The shortest path has length %d\n",best);
        
    }
    return 0;
}
