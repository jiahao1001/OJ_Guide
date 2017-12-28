#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
#include<set>
#include<string>
#include<limits.h>
#include<algorithm>
#include<float.h>
using namespace std;
const int MAXN = 50010;
int N,W;
int x[MAXN],y[MAXN];
stack<int> sky;
int main(){
    scanf("%d%d",&N,&W);
    for(int i=0;i<N;i++)
        scanf("%d%d",x+i,y+i);
    x[N]=W+1,y[N]=0;
    sky.push(y[0]);
    int total = 0;
    for(int i=1;i<=N;i++){
        while(!sky.empty() && y[i]<sky.top()) {
            //printf("%d pop %d\n",i,sky.top());
            sky.pop(), total++;
        }
        if(!sky.empty() && y[i]==sky.top()) continue;
        sky.push(y[i]);
    }
    printf("%d\n",total);
    return 0;
    
}
