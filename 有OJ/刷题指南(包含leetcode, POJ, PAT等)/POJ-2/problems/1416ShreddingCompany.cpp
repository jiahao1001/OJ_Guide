#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int n,target;
int path[6];
int cnt;
int best;
int best_path[6];
bool rejected;
char buf[10];
int len;
int appear;
void dfs(int cur,int level,int sum){
    if(cur==len){
        if(sum>target) return;
        if(target-sum==best){
            appear++;
            return;
        }
        if(target-sum<best) {
            appear = 1;
            best = target-sum;
            for(int i=0;i<level;i++)
                best_path[i] = path[i];
            cnt = level;
        }
        return;
    }
    int num = 0;
    for(int i=cur;i<len;i++){
        num = num*10+buf[i]-'0';
        path[level] = num;
        dfs(i+1,level+1,sum+num);
    }
    
    
}
int main(){
    while(scanf("%d%d",&target,&n), n||target){
        if(n==target){
            printf("%d %d\n",n,n);
            continue;
        }
        sprintf(buf,"%d",n);
        len = strlen(buf);
        appear = 0;
        rejected = false;
        best = target;
        cnt = 0;
        dfs(0,0,0);
        if(appear>1) printf("rejected\n");
        else if(best==target){
            printf("error\n");
        }
        else{
            printf("%d",target-best);
            printf(" %d",best_path[0]);
            for(int i=1;i<cnt;i++) printf(" %d",best_path[i]);
            printf("\n");
        }
    }
    return 0;
}
