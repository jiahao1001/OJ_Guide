#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
const int inf = INT_MAX/2;
const int seed = 19;
const int M  = 20201;
int p[100];
char word[50000][60];
int len[50000];
int code[50000][60]; //hash code
char *to_i = "22233344115566070778889990";
char phone[120];
int word_h[50000];
int h[120];
int dp[120],dm[120];
int n;
int m;
inline bool match(int i,int s){
    //word i, match phone starting from s
    int j;
    for(j=0;j<len[i]&&s<n;j++,s++)
        if(code[i][j]!=phone[s]) return false;
    return j==len[i];
}
inline int get_h(int i,int j){
    return (h[j]-(i==0?0:h[i-1])+M) % M;
}
void print(int i){
    if(i==-1)return;
    int j = dm[i];
    int d = len[j];
    //printf("%s ",word[j]);
    print(i-d);
    printf("%s",word[j]);
    if(i!=n-1)printf(" ");
    
}
int main()
{
    scanf("%s",phone);
    n = strlen(phone);
    for(int i=0;i<n;i++) dp[i] = inf;
    p[0] = 1;
    for(int i=1;i<n;i++)
        p[i] = (p[i-1]*seed)%M;
    h[0] = phone[0] - '0';
    for(int i=1;i<n;i++)
        h[i] = (h[i-1]+(phone[i]-'0')*p[i])%M;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%s",word[i]);
        len[i] = strlen(word[i]);
        for(int j=0;j<len[i];j++)
            code[i][j] = to_i[word[i][j]-'a'];
        word_h[i] = 0;
        for(int j=len[i]-1;j>=0;j--)
            word_h[i] = (word_h[i]*seed+code[i][j]-'0')%M;
    }
    
    for(int j=0;j<m;j++)
        if(word_h[j]==get_h(0,len[j]-1) && match(j,0)){
            dp[len[j]-1] = 1;
            dm[len[j]-1] = j;
            //cout<<word[j]<<endl;
        }
    for(int i=1;i<n;i++){
        if(dp[i-1]==inf) continue;
        for(int j=0;j<m;j++){
            if(i+len[j]>n) continue;
            if(word_h[j]*p[i]%M!=get_h(i,i+len[j]-1) || !match(j,i)) continue;
            //cout<<" "<<i<<" "<<word[j]<<endl;
            if(dp[i-1]+1<dp[i+len[j]-1]){
                dp[i+len[j]-1] = dp[i-1]+1;
                dm[i+len[j]-1] = j;
            }
        }
    }
    if(dp[n-1]==inf) printf("No solution.\n");
    else{
        print(n-1);
        printf("\n");
    }
    
    return 0;
}
