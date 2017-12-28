#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
int n;
char cmd[10];
int m,cnt1,cnt2;
int main(){
    while(scanf("%d",&n),n){
        cnt1 = cnt2 = 0;
        for(int i=0;i<n;i++){
            scanf("%s%d",cmd,&m);
            if(!strcmp(cmd,"DROP")){
                //put to pile1
                cnt1 += m;
                printf("DROP 1 %d\n",m);
            }else{
                if(cnt2>=m){
                    printf("TAKE 2 %d\n",m);
                    cnt2 -= m;
                }else{
                    if(cnt2)printf("TAKE 2 %d\n",cnt2);
                    m-=cnt2;
                    cnt2 = 0;
                    cnt2+=cnt1;
                    if(cnt1)printf("MOVE 1->2 %d\n",cnt1);
                    cnt1 = 0;
                    if(m)printf("TAKE 2 %d\n",m);
                    cnt2-=m;
                }
            }
        }
        
    }
    return 0;
}
