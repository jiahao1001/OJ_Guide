#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int MAXN = 1001;
int rating[MAXN];
int N,T;
int main()
{
    scanf("%d%d",&N,&T);
    for(int i=1;i<=N;i++) scanf("%d",rating+i);
    if(N==1){
        for(int i=1;i<=T;i++) printf("1\n");
        return 0;
        
    }
    while(T--){
        //get max
        int best = INT_MIN;
        int id = -1;
        for(int i=1;i<=N;i++)
            if(best<rating[i]) best = rating[i], id = i;
        printf("%d\n",id);
        int add = best/(N-1);
        int extra = best%(N-1);
        rating[id] = 0;
        for(int i=1;i<=N;i++)
            if(i!=id) rating[i]+=add;
        int cnt = 0;
        for(int i=1;cnt<extra&&i<=N;i++)
            if(i!=id) rating[i]++, cnt++;
            
    }
    return 0;
}
