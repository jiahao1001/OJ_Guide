#include<queue>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<set>
using namespace std;
bool next(char *p,char *q){
    //q is a next word for p
    int p_len = strlen(p),q_len = strlen(q);
    if(p_len+1!=q_len) return false;
    for(int i=0;i<q_len;i++){
        int k = 0;
        for(int j=0;j<q_len;j++){
            if(j==i)continue;
            if(p[k]!=q[j]) break;
            k++;
        }
        if(k==p_len) return true;
    }
    return false;
}
int n;
char s[90];
char word[1000][90];
vector<int> g[1000];
int v[1000],init;
int best,lst;
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++){
        scanf("%s",word[i]);
        if(!strcmp(word[i],s)) init=i;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(next(word[i],word[j])) g[i].push_back(j);
    memset(v,0,sizeof v);
    queue<int> Q;
    Q.push(init);
    v[init]=1;
    best = init;
    lst = 3;
    int len;
    while(!Q.empty()){
        int h = Q.front();
        Q.pop();
        if((len=strlen(word[h]))>lst){
            lst = len, best = h;
        }
        for(int i=0;i<g[h].size();i++){
            int j = g[h][i];
            if(v[j]) continue;
            v[j] = 1;
            Q.push(j);
        }
    }
    printf("%s\n",word[best]);
    return 0;
}
