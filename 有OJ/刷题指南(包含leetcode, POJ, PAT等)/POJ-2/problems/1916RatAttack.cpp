#include<iostream>
#include<stdio.h>
using namespace std;
const int N = 1025;
int d,n;
int rat[1030][1030];
int A[1030];
//sweep line top and down
int main()
{
    int t,x,y,cnt;
    scanf("%d",&t);
    while(t--){
        memset(A,0,sizeof A);
        memset(rat,0,sizeof rat);
        scanf("%d%d",&d,&n);
        // 1 .. 1025
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&cnt);
            rat[x+1][y+1] = cnt;
        }
        for(int i=1;i<=d+1;i++)
            for(int j=1;j<=N;j++)
                A[j]+=rat[i][j];
        int l_cnt = d+1;
        
        int best = -1;
        for(int i=1;i<=N;i++){
            int win = 0;
            for(int j=1;j<=d+1;j++) win+=A[j];
            int r_cnt = d+1;
            for(int j=1;j<=1025;j++){
                if(win>best) best = win, x=i,y=j;
                if(r_cnt==2*d+1) win-=A[j-d],r_cnt--;
                if(j+d+1<=1025) r_cnt++, win+=A[j+d+1];
            }
            if(l_cnt == 2*d+1){
                for(int j=1;j<=1025;j++)
                    A[j] -= rat[i-d][j];
                l_cnt--;
            }
            if(i+d+1<=1025){
                l_cnt++;
                for(int j=1;j<=1025;j++)
                    A[j] += rat[i+d+1][j];
            }
            
        }
        printf("%d %d %d\n",x-1,y-1,best);
    }
    return 0;
}
