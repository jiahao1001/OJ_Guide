#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 100001;
int c,n;
int A[N];
int sum[N];
int main()
{
    while(scanf("%d%d",&c,&n),c||n){
        for(int i=1;i<=n;i++)scanf("%d",A+i);
        memset(sum,-1,sizeof(sum));
        sum[0] = 0;
        int s = 0;
        int b,e;
        for(int i=1;i<=n;i++){
            s+=A[i];
            s%=c;
            if(sum[s]!=-1){
                b = sum[s]+1;
                e = i;
                break;
            }
            sum[s] = i;
        }
        printf("%d",b);
        for(int i=b+1;i<=e;i++)
            printf(" %d",i);
        printf("\n");
        
    }
    return 0;
}
