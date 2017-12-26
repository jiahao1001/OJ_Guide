#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<map>
using namespace std;
typedef long long LL;
char p[30][30];
int down[10][10],rgt[10][10];
int n,m;
int a[11],x,y;
int b[8];
map<LL,int> f[2];
inline LL calc(){
    LL s = 0;
    int k = 0;
    for(int i=0;i<8;i++) b[i] = 0;
    for(int i=0;i<=m;i++)
        if(a[i]) a[i] = b[a[i]]?b[a[i]]:b[a[i]]=++k;
    for(int i=m;i>=0;i--) s<<=3, s|=a[i];
    return s;
}
inline void decode(LL t){
    for(int i=0;i<=m;i++) a[i] = t&7,t>>=3;
}
void push(map<LL,int> &f,LL x,int d){
    if(!f.count(x)) f[x] = INT_MAX;
//    cout<<"push "<<d<<endl;
    f[x] = min(f[x],d);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        gets(p[0]);
        for(int i=0;i<2*n+1;i++)
            gets(p[i]);
        for(int i=0;i<n-1;i++)
            for(int j=0;j<m;j++)
                down[i][j] = p[2*i+2][2*j+1]-'0';
        for(int i=0;i<n;i++)
            for(int j=0;j<m-1;j++)
                rgt[i][j] = p[2*i+1][2*j+2]-'0';
        int cur=0,nxt = 1;
        f[cur].clear();
        f[cur][0] = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                //              printf("(%d,%d)\n",i,j);
                f[nxt].clear();
                for(map<LL,int>::iterator it = f[cur].begin();it!=f[cur].end();it++){
                    decode(it->first);
                    int d;
                    if(j==1 && a[0]!=0) continue;
                    x=a[0],y=a[j];
                    if(!x && !y){
                        //new
                        a[0] = a[j] = 7;
                        push(f[nxt],calc(),it->second);
                    }else if(x&&y){
                        d = it->second;
                        d+= rgt[i-1][j-2] + down[i-2][j-1];
                        if(x==y && (i!=n || j!=m)) continue;//form the circle only in last grid.
                        for(int k=0;k<=m;k++)
                            if(a[k]==x) a[k]=y;
                        a[0] = a[j] = 0;
                        push(f[nxt],calc(),d);
                    }else if(x && !y){
                        // ->|
                        d = it->second + rgt[i-1][j-2];
                        push(f[nxt],calc(),d);
                        a[0] = 0, a[j] = x;
                        push(f[nxt],calc(),d);
                    }else{
                        d = it->second + down[i-2][j-1];
                        push(f[nxt],calc(),d);
                        a[j] = 0, a[0] = y;
                        push(f[nxt],calc(),d);
                    }
                }
                cur ^= 1, nxt ^= 1;
            }
        printf("%d\n",f[cur][0]);
    }
    return 0;
}
