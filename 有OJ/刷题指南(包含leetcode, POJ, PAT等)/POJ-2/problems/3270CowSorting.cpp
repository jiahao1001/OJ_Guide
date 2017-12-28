#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
const int N = 100005;
struct Node{
    int val;
    int cnt;
} a[N];
int n,m[N],tot,t[N];
bool flag[N];
void dfs(int u){
    for(int i=0;i<n;i++)
        if(t[i]==u && !flag[i]){
            flag[i] = 1;
            a[tot].cnt++;
            a[tot].val = min(a[tot].val,t[i]);
            dfs(m[i]);
        }
    
}
int main()
{
    scanf("%d",&n);
    int sum = 0, mmin = 1<<30;
    for(int i=0;i<n;i++){
        scanf("%d",m+i);
        sum += m[i];
        t[i] = m[i];
        mmin = min(mmin,m[i]);
    }
    sort(m,m+n);
    tot = 0;
    for(int i=0;i<n;i++){
        if(flag[i]) continue;
        a[tot].val = t[i];
        a[tot].cnt = 1;
        flag[i] = true;
        dfs(m[i]);
        tot++;
    }
    for(int i=0;i<tot;i++)
        sum += min(a[i].val*(a[i].cnt-2),mmin*(a[i].cnt+1)+a[i].val);
    printf("%d\n",sum);
    return 0;
}
