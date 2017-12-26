#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;
/*

* one or more  0
! one          1 
? zero or one  2
*->*
?-> !??
!-> !!*

*/
char a[300],b[300];
int x[600],y[600],cnt;
int dp[605][605];
int X,Y;
string sp = "!?*";
map<string,int> M;
void norm(char *p,int *A,int &n){
  string s="";
  n = 1;
  while(true){
     if(*p!='.' && *p!='\0')
     s+=*p;
     if(*p == '.' || *p=='\0') {
          if(sp.find(s)==string::npos) {
            if(M.find(s) == M.end()) M[s] = cnt++;
            A[n++] = M[s];
          }
          s = "";
     }else if(*p == '!') {
          A[n++] = 1;
          A[n++] = 1;
          A[n++] = 0;
     }else if(*p == '*') {
          A[n++] = 0;
     }else if(*p == '?') {
          A[n++] = 1;
          A[n++] = 2;
          A[n++] = 2;
     }
     if(*p == '\0') break;
     p++;
  }
  n--;
}
void solve(){
  memset(dp,0,sizeof(dp));
  dp[0][0] = 1;
  for(int i=1;i<=X;i++)
    for(int j=1;j<=Y;j++){
      if(x[i]>2 && y[j]>2 ) dp[i][j] = (x[i]==y[j])?dp[i-1][j-1]:0;
      else{
        if(x[i]==0)
          dp[i][j] = dp[i][j] || dp[i-1][j-1] || dp[i][j-1];
        if(x[i]==1)
          dp[i][j] = dp[i][j] || dp[i-1][j-1];
        if(x[i]==2)
          dp[i][j] = dp[i][j] || dp[i-1][j] || dp[i-1][j-1];
        if(y[j]==0)
          dp[i][j] = dp[i][j] || dp[i-1][j-1]|| dp[i-1][j];
        if(y[j]==1)
          dp[i][j] = dp[i][j] || dp[i-1][j-1];
        if(y[j]==2)
          dp[i][j] = dp[i][j] || dp[i][j-1] || dp[i-1][j-1];
      }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
       scanf("%s%s",a,b);
       M.clear(); //map to 3,4..
       cnt = 3;
       norm(a,x,X);
       norm(b,y,Y);
       solve();
       if(dp[X][Y]) printf("YES\n");
       else printf("NO\n");
    }
    return 0;
}
