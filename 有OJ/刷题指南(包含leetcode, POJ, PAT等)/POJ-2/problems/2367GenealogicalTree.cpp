#include<iostream>
#include<map>
#include<set>
#include<string>
#include <vector>
#include <stdlib.h>
#include <climits>
#include <utility>
#include <stdio.h>
#include <assert.h>
#include <stack>
#include <string.h>
using namespace std;
const int N = 101;
int n;
int g[N][N];
stack<int> S;
int visited[N];
void dfs(int i){
    visited[i] = 1;
    for(int j=1;j<=n;j++)
        if(g[i][j] && !visited[j]) dfs(j);
    S.push(i);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int j;
        while(scanf("%d",&j),j){
            g[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++)
        if(!visited[i]) dfs(i);
    printf("%d",S.top());
    S.pop();
    while(!S.empty()){
        printf(" %d",S.top());
        S.pop();
    }
    printf("\n");
}
