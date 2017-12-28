#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;

int Q,D,N,P,C;

int main()
{
    while(scanf("%d%d%d%d%d",&Q,&D,&N,&P,&C), Q||D||N||P||C){
        int q,d,n,p;
        int best = INT_MAX;
        for(int i=0;i<=Q && i*25<=C;i++)
            for(int j=0;j<=D && i*25+j*10<=C;j++)
                for(int k=0;k<=N && i*25+j*10+k*5<=C;k++)
                    for(int l=0;l<=P && i*25+j*10+k*5+l<=C;l++){
                        if(i*25+j*10+k*5+l==C){
                            if(i+j+k+l<best) best = i+j+k+l, q=i,d=j,n=k,p=l;
                        }
                    }
        if(best == INT_MAX) printf("Cannot dispense the desired amount.\n");
        else printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",q,d,n,p);
    }
    return 0;
}
