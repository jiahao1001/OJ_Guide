#include<iostream>
#include<stdio.h>
using namespace std;
int rate[100];
int n,p;
int cnt[100]; //prob i is consider simple cnt[i] time 
int main(){
    cin>>n>>p;
    for(int i=0;i<p;i++) cnt[i] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++)
            scanf("%d",rate+j);
        int mx = -1,mi = 2000;
        int h,s;
        for(int j=0;j<p;j++)
            mx = max(mx,rate[j]), mi = min(mi,rate[j]);
        for(int j=0;j<p;j++)
            if(mx==rate[j]) cnt[j]-=100;
            else if(mi==rate[j]) cnt[j]++;
    }
    int tot = 0;
    bool begin = true;
    for(int i=0;i<p;i++)
        if(cnt[i]>n/2){
            tot++;
            if(tot>1)printf(" ");
            printf("%d",i+1);
        }
    if(!tot)
        printf("%d\n",tot);
    else printf("\n");
    return 0;
}
