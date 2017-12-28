#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int dp[40][40][11];
int mole[40][40][11];
int n,d,m;

inline int sqr(int x)
{
    return x*x;
}
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    while(scanf("%d%d%d",&n,&d,&m),n||d||m)
    {
        int x,y,t;
        int max_t=0;
        n+=20;
        memset(dp,0,sizeof(dp));
        memset(mole,0,sizeof(mole));
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&x,&y,&t), mole[10+x][10+y][t]=1,max_t=max(max_t,t);
        for(t=1;t<=max_t;t++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                {
                    //x,y in the circle of radius d  max dp[x][y][t-1] + on line moles)
                    int x1=max(0,i-d),x2=min(n-1,i+d);
                    int y1=max(0,j-d),y2=min(n-1,j+d);
                    for(x=x1;x<=x2;x++)
                        for(y=y1;y<=y2;y++)
                            if(sqr(x-i)+sqr(y-j)<=sqr(d))
                            {
                                int moles_on_line=0;
                                int dx=x-i,dy=y-j;
                                int g=gcd(abs(dx),abs(dy));
                                int ux,uy;
                                ux=i,uy=j;
                                while(ux!=x || uy!=y){
                                    if(mole[ux][uy][t]) moles_on_line++;
                                    ux+=(dx/g),uy+=(dy/g);
                                }
                                if(mole[x][y][t]) moles_on_line++;
                                
                                
                                dp[i][j][t]=max(dp[i][j][t],dp[x][y][t-1]+moles_on_line);
                            }
                    //cout
                }
        int score = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) score = max(score,dp[i][j][max_t]);
        printf("%d\n",score);
    }
    return 0;
}
