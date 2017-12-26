#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 100;
int dp[10001][N];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    dp[0][0] = 1;
    int a;
    int b,c;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        for(int j=0;j<k;j++)
            if(dp[i-1][j]){
                b = (j+a)%k;
                if(b<0) b+=k;
                c = (j-a)%k;
                if(c<0) c+=k;
             	dp[i][b]=1;
                dp[i][c]=1;
            }
    }
    if(dp[n][0]) printf("Divisible\n");
    else printf("Not divisible\n");

    return 0;
}

