#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
const int N = 60001;
PII p[N];
int A[N];
int n,m;
void add(int x,int d){
    while(x<=n) A[x]+=d, x+=(x&(-x));
}
int get(int x){
    int sum = 0;
    while(x) sum+=A[x],x-=(x&(-x));
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int q=1;q<=t;q++){
        scanf("%d%d",&n,&m);
        n+=m;
        for(int i=0;i<n;i++)
            scanf("%d%d",&p[i].first,&p[i].second);
        sort(p,p+n);
        //inversion of y
        memset(A,0,sizeof A);
        int cnt = 0;
        //>=
        for(int i=0;i<n;i++){
            int y = p[i].second;
            //printf("%d ",y);
            cnt+= get(n)-get(y-1);
            add(y,1);
        }
        printf("Scenario #%d:\n%d\n\n",q,cnt);
    }
    return 0;
}
