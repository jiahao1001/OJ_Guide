#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
typedef long long LL;
LL p[500];
int k,m;
inline bool check(LL len){
    //greedy, cnt<=m
    LL cur = 0;
    int cnt = 0;
    for(int i=0;i<k;i++){
        if(p[i]>len) return false;
        if(cur+p[i]>len){
            cur = p[i];
            cnt++;
        }else cur+=p[i];
    }
    cnt++;
    return cnt<=m;
}
int cut[500];
void print_answer(LL len){
    LL cur = 0;
    int cnt = 0;
    cut[k-1] = 1;
    for(int i=k-1;i>=0;i--){
        if(cur+p[i]>len){
            cur = p[i];
            cut[i] = 1;
            cnt++;
        }else cur+=p[i];
    }
    cnt++;
    
    //assign one book
    for(int i=0;i<k && cnt<m; i++)
        if(!cut[i]) cut[i] = 1, cnt++;
    for(int i=0;i<k;i++){
        printf("%lld",p[i]);
        if(i!=k-1)printf(" ");
        else printf("\n");
        if(cut[i] && i!=k-1) printf("/ ");
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&k,&m);
        LL l = 0, r = 0;
        for(int i=0;i<k;i++)
            scanf("%lld",p+i),r+=p[i];
        LL mid;
        while(l+1<r){
            mid = (l+r)>>1;
            if(check(mid)) r = mid;
            else l = mid;
        }
        //printf("%lld\n",r);
        memset(cut,0,sizeof(cut));
        print_answer(r);
    }
    return 0;
}
