#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int sg[2002];
int getsg(int n)
{
    if(n<=0) return 0;
    if(sg[n]>=0) return sg[n];
    bool vis[2002]={0};
    for(int i=1;i<=n;i++){
        vis[getsg(n-i-2)^getsg(i-3)]=1;
    }
    int i=0;
    while(vis[i]) i++;
    return sg[n]=i;
}
int main()
{
    int n;
    memset(sg,-1,sizeof(sg));
    while(scanf("%d",&n)!=-1){
        puts(getsg(n)?"1":"2");
    }
    return 0;
}
