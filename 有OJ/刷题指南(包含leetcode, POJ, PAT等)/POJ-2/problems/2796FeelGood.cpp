#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
typedef long long LL;
const int N = 100100;
int st[N];
LL a[N],sum[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",a+i), sum[i]+=sum[i-1]+a[i];
    int top = 0;
    a[n+1] = -1;
    LL tmp,ans = -1;
    int l,r;
    for(int i=1;i<=n+1;i++){
        while(top!=0 && a[st[top]]>a[i]){
            tmp = a[st[top]]*(sum[i-1]-sum[st[top-1]]);
            if(tmp>ans) ans = tmp, l = st[top-1]+1, r = i-1;
            top --;
        }
        st[++top] = i;
    }
    printf("%lld\n%d %d\n",ans,l,r);
    
}
