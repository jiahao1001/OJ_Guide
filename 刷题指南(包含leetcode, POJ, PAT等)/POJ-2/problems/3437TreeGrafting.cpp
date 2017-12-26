#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
#include<utility>
using namespace std;
const int N = 20010;
char s[N];
int h1,h2;
int len;
inline void before(){
    int d = 0;
    for(int i=0;i<len;i++){
        if(s[i]=='d') d++;
        else d--;
        h1=max(d,h1);
    }
}
int dfs(int i,int d){//return number of token eaten
    int st = i;
    //printf("(%d,%d)\n",i,d);
    h2 = max(h2,d);
    while(i<len && s[i]=='d') {//a subtree
        i+=dfs(i+1,++d);
    }
    //printf("tree size %d\n",i-st);
    return i-st+2;
}

int main()
{
    int t=0;
    while(scanf("%s",s),s[0]!='#'){
        h1 = h2 = 0;
        len = strlen(s);
        before();
        dfs(0,0);
        printf("Tree %d: %d => %d\n",++t,h1,h2);
    }
    return 0;
}
