#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
const int N = 2000;
int f[N],g[N];
int h[N];
int p[N];
int fd,gd,hd,pd;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&fd);
        for(int i=0;i<fd;i++) scanf("%d",&f[fd-1-i]);
        scanf("%d",&gd);
        for(int i=0;i<gd;i++) scanf("%d",&g[gd-1-i]);
        memset(p,0,sizeof p);
        for(int i=fd-1;i>=0;i--)
            if(f[i]){
                for(int j=0;j<gd;j++)
                    if(g[j]) p[i+j] ^= 1;
            }
        pd = fd+gd-1;
        
        scanf("%d",&hd);
        for(int i=0;i<hd;i++) scanf("%d",&h[hd-1-i]);
        while(pd>=hd){
            int d = pd-hd;
            for(int i=0;i<hd;i++)
                if(h[i]) p[i+d] = (p[i+d]+h[i])%2;
            while(pd>0 && p[pd-1]==0) pd--;
        }
        printf("%d",pd);
        for(int i=pd-1;i>=0;i--){
            printf(" %d",p[i]);
        }
        printf("\n");
    }
    return 0;
}
