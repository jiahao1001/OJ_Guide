#include<iostream>
#include<stdio.h>
using namespace std;
int D[30001];
int sum[30001];
int N;
int main()
{
    scanf("%d",&N);
    sum[0]=0;
    for(int i=1;i<=N;i++){
        scanf("%d",D+i);
        if(D[i]==1){
            sum[i]=sum[i-1]+1;
        }else sum[i]=sum[i-1];
    }
    
    int best=sum[N];
    for(int i=1;i<=N;i++)  //1..i is 1
    {
        best=min(best,i-sum[i]+sum[N]-sum[i]);
        //cout<<i<<" "<<best<<endl;
    }
    printf("%d\n",best);
    return 0;
}
