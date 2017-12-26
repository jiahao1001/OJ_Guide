#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<stack>
#include<utility>
using namespace std;
typedef pair<int,int> PII;
int n[26],m[26];
int cnt;
char s[100];
int tot;
int len;
int rgt[100];//where is my right bracket
PII dfs(int i,int j){
    if(i==j){
        int k = s[i]-'A';
        if(!n[k]) throw -1;
        return make_pair(n[k],m[k]);
    }
    int n1,m1,n2,m2;
    PII p1,p2;
    p1 = dfs(i+1,rgt[i+1]);
    p2 = dfs(rgt[i+1]+1,j-1);
    
    n1=p1.first,m1=p1.second;
    n2=p2.first,m2=p2.second;
    if(m1!=n2) throw -1;
    tot+=n1*m1*m2;
    return make_pair(n1,m2);
}
int main()
{
    char c;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++){
        scanf("%s",s);
        c = s[0];
        scanf("%d%d",&n[c-'A'],&m[c-'A']);
    }
    while(scanf("%s",s)!=EOF){
        tot = 0;
        len = strlen(s);
        for(int i=0;i<len;i++) rgt[i] = i;
        stack<int> left;
        for(int i=0;i<len;i++){
            if(s[i]=='(') left.push(i);
            else if(s[i]==')'){
                int j = left.top();
                left.pop();
                rgt[j] = i;
            }
        }
        try{
            dfs(0,len-1);
            printf("%d\n",tot);
        }catch(int e){
            printf("error\n");
        }
    }
    return 0;
}
