/*KMP algorithm

 */

#include<iostream>
#include<stdio.h>

char W[10010],T[1000010];
int N;
int next[10010];


//match W again T, return the occurence
int kmp()
{
    //compute next of W
    int n=strlen(W+1);
    int m=strlen(T+1);
    next[1]=0;
    int i,j=0;
    for(i=2;i<=n;i++)
    {
        while(j>0 && W[j+1]!=W[i]) j=next[j];
        if(W[j+1]==W[i]) j++;
        next[i]=j;
    }
    //for(int i=1;i<=n;i++)
    //  printf("fail %d->%d\n",i,next[i]);
    int cnt = 0;
    j=0;
    for(i=1;i<=m;i++)
    {
        while(j>0 && W[j+1]!=T[i]) j=next[j];
        if(W[j+1]==T[i]) j++;
        if(j==n) cnt++;//,printf("found %d\n",i);
        
    }
    return cnt;
}
int main()
{
    scanf("%d",&N);
    while(N--){
        scanf("%s",W+1);
        scanf("%s",T+1);
        printf("%d\n",kmp());
    }
    return 0;
}
