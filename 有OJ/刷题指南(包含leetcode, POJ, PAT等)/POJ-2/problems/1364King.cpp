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
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<numeric>
#include<map>
using namespace std;
const int N = 110;
const int INF = INT_MAX/2;
int g[N][N];
int dist[N];
int n,m;
int main(){
    while(cin>>n,n){
        cin>>m;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++) g[i][j] = INF;
        for(int i=0;i<=n;i++) dist[i] = 0;
        int x,y,d;
        string sym;
        for(int i=0;i<m;i++){
            cin>>x>>y>>sym>>d;
            if(sym=="lt") g[x-1][x+y]=d-1;
            else g[x+y][x-1]=-d-1;
        }
        //for(int i=0;i<=n;i++) g[i][n+1]=0;
        //dist[0] = 0;
        for(int k=0;k<n;k++)
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++) if(dist[i]+g[i][j]<dist[j]) dist[j] = dist[i]+g[i][j];
        bool fail = false;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++) if(dist[i]+g[i][j]<dist[j]){
                fail = true;
            }
        if(fail) cout<<"successful conspiracy"<<endl;
        else cout<<"lamentable kingdom"<<endl;
                
    }
    return 0;
}
