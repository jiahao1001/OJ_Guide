#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
int n;
int y[20],a[20],b[20];
bool check(int s){
    for(int i=0;i<n;i++)
        if((s-y[i])%(b[i]-a[i])) return false;
    return true;
}
int main()
{
    int q=1;
    while(scanf("%d",&n),n){
        int ans = -1;
        int s = 0;
        for(int i=0;i<n;i++)
            scanf("%d%d%d",y+i,a+i,b+i),s=max(s,y[i]);
        for(;s<10000;s++){
            if(check(s)) break;
        }
        printf("Case #%d:\n",q++);
        if(s>=10000)printf("Unknown bugs detected.\n");
        else printf("The actual year is %d.\n",s);
        printf("\n");
    }
    return 0;
}
