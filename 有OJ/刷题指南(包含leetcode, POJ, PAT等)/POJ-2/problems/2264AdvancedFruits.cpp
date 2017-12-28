#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
char s1[120],s2[120];
int dp[120][120],a[120][120];
int mark1[120];
int mark2[120];
void print(int n,int m){
    if(!n || !m) return;
    char c=' ';
    if(!a[n][m])c=s1[n],mark1[n]=1,mark2[m]=1,n--,m--;
    else if(a[n][m]==-1) n--;
    else m--;
    print(n,m);
    //if(c!=' ') putchar(c);
}
int main()
{
    while(scanf("%s%s",s1+1,s2+1)!=EOF){
        int n = strlen(s1+1), m = strlen(s2+1);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                dp[i][j] = dp[i-1][j],a[i][j] = -1;
                if(dp[i][j-1]>dp[i][j]) dp[i][j] = dp[i][j-1],a[i][j] = 1;
                if(s1[i]==s2[j] && dp[i-1][j-1]+1>dp[i][j])
                    dp[i][j] = dp[i-1][j-1]+1,a[i][j] = 0;
            }
        
        memset(mark1,0,sizeof mark1);
        memset(mark2,0,sizeof mark2);
        print(n,m);
        //printf("\n");
        //printf("%d\n",dp[n][m]);
        int i=1,j=1;
        while(i<=n||j<=m){
            while(!mark1[i] && i<=n) putchar(s1[i++]);
            if(i<=n) i++;
            while(!mark2[j] && j<=m) putchar(s2[j++]);
            if(j<=m) putchar(s2[j++]);
            //else j++;
        }
        putchar('\n');
        
    }
    return 0;
}
