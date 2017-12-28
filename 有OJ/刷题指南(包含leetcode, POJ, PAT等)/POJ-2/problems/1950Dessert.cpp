#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long LL;
int n;
int cnt;
char answer[21][20];
LL get(char c,LL x,LL y){
    if(c=='+') return x+y;
    if(c=='-') return x-y;
    if(c=='.') {
        if(y>9) return 100*x+y;
        else return 10*x+y;
    }
}
char path[20];
void dfs(int i,char last,long long num,long long tot){
    // + - .
    if(i==n){
        tot = get(last,tot,num);
        if(tot==0){
            if(cnt<=19) for(int i=1;i<n;i++) answer[cnt][i] = path[i];
            cnt++;
        }
        return;
    }
    //+
    path[i]='+';
    dfs(i+1,'+',i+1,get(last,tot,num));
    path[i]='-';
    dfs(i+1,'-',i+1,get(last,tot,num));
    path[i] = '.';
    dfs(i+1,last,get('.',num,i+1),tot);
}
int main()
{
    cnt = 0;
    scanf("%d",&n);
    dfs(1,'+',1,0);
    for(int i=0;i<min(20,cnt);i++){
        for(int j=1;j<n;j++)
            printf("%d %c ",j,answer[i][j]);
        printf("%d\n",n);
    }
    printf("%d\n",cnt);
    
    return 0;
}
