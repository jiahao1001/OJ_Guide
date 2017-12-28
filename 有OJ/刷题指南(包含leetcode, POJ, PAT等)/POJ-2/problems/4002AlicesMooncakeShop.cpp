#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
struct node{
    char s[10];
    int day,year, H,R;
    void get(){
        scanf("%s%d%d%d%d",s,&day,&year,&H,&R);
    }
};
const int MAX = 100005;
node b[2505];
int n,m,S,T,p[MAX],t[2505];
char map[12][10] = {"Jan","Feb","Mar","Apr","May","Jun",
                    "Jul","Aug","Sep","Oct","Nov","Dec"};
int M[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

int Y[]={365,366};
int getMonth(char *s){
    int i;
    for(i=0;i<12;i++) if(strcmp(map[i],s)==0) break;
    return i+1;
}
int leap(int x){
    return x%400==0 || x%100&&x%4==0;
}
int cal(node a){
    int year=a.year;
    int month=getMonth(a.s);
    int day=a.day;
    int ans=0,t,i;
    for(i=2000;i<year;i++) ans+=Y[leap(i)];
    t=leap(year);
    for(i=1;i<month;i++) ans+=M[t][i];
    ans+=day-1;
    return ans*24+a.H+1;
}

struct Node{
    int x,y;
};
Node Q[MAX];
int head,tail;

int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        int i;
        for(i=1;i<=n;i++) b[i].get(),t[i] = cal(b[i]);
        scanf("%d%d",&T,&S);
        for(i=1;i<=m;i++) scanf("%d",&p[i]);
        long long ans = 0;
        int j=1;
        head = tail = 0;
        for(i=1;i<=m;i++){
            while(head<tail&&Q[tail-1].x+(i-Q[tail-1].y)*S>=p[i])
                tail --;
            Q[tail].x = p[i];
            Q[tail].y = i;
            tail++;
            while(j<=n&&t[j]==i){
                while(head<tail && Q[head].y+T<i) head++;
                ans += (long long)((Q[head].x+(i-Q[head].y)*S)*b[j].R);
                j++;
                           
            }
            
        }
        printf("%lld\n",ans);
        
    }
    return 0;
}
