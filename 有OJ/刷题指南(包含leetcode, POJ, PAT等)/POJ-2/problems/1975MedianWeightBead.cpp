#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int t,n,m;
int heavy[100][100];
int light[100][100];
int main(){
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d%d",&n,&m);
        int lim = (n+1)/2;
        memset(heavy,0,sizeof heavy);
        memset(light,0,sizeof light);
        for(int i=0;i<m;i++){
            scanf("%d%d",&a,&b);
            heavy[a][b] = 1;
            light[b][a] = 1;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    if(heavy[i][k] && heavy[k][j]) heavy[i][j] = 1;
                    if(light[i][k] && light[k][j]) light[i][j] =1;
                }
        int cnt = 0;
        for(int i=1;i<=n;i++){
            a=b=0;
            for(int j=1;j<=n;j++){
                if(heavy[j][i]) a++;
                if(light[j][i]) b++;
            }
            if(a>=lim || b>=lim) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
