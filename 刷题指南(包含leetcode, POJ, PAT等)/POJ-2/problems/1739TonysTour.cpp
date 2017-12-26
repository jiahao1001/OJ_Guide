#include<iostream>
#include<map>
#include<stdio.h>
#include<string.h>
using namespace std;
typedef long long LL;
int n,m;
int g[20][20];
char s[20];
int a[20],b[20];
int x,y,cur,nex,nx,ny;
map<int,int> f[2];
inline LL calc(){
    LL s = 0, k = 0;
    for(int i=0;i<8;i++) b[i] = 0;
    for(int i=0;i<=m;i++)
        if(a[i]) a[i] = b[a[i]]?b[a[i]]:b[a[i]]=++k;
    for(int i=m;i>=0;i--) s<<=3, s|=a[i];
    return s;
}
void decode(LL t){
    for(int i=0;i<=m;i++) a[i] = t&7,t>>=3;
}
void up(int w,int t,LL s)
{
    if ( x && y ) {
        if ( x != y || ( w == nx && t == ny ) ) {
            for(int i=0;i<=m;i++)
                if ( a[i] == y ) a[i] = x;
            a[0] = a[t] = 0;
            f[nex][calc()]+=s;
        }
    } else if ( x || y ) {
        f[nex][calc()]+=s;
        swap( a[0] , a[t] );
        f[nex][calc()]+=s;
    } else {
        a[0] = a[t] = 7;
        f[nex][calc()]+=s;
    }
}

int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        memset(g,0,sizeof g);
        nx = 0;
        for(int i=n;i>=1;i--){
            scanf("%s",s+1);
            for(int j=1;j<=m;j++)if(s[j]=='.') g[i][j] = 1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(g[i][j]) nx = i,ny = j;//last non-block
        f[0].clear();
        cur = 0, nex = 1;
        memset(a,0,sizeof a);
        a[1] = a[m] = 1;
        f[0][calc()] += 1;
        
        //work
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                f[nex].clear();
                for(map<int,int>::iterator it=f[cur].begin();it!=f[cur].end();it++){
                    decode(it->first);
                    if(j==1 && a[0]) continue;
                    x=a[0], y = a[j];
                    if(g[i][j]) up(i,j,it->second);
                    else if(!x && !y) f[nex][it->first]+=it->second;
                }
                swap(cur,nex);
            }
        printf("%d\n",f[cur][0]);
    }
    return 0;
}
