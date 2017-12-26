#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
PII monkey[50000];
int main()
{
    int x,y;
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++){
            scanf("%d%d",&x,&y);
            monkey[i].first = x, monkey[i].second = y;
        }
        sort(monkey,monkey+n);
        int cnt = 1;
        x = monkey[n-1].first, y = monkey[n-1].second;
        for(int i=n-2;i>=0;i--){
            if(monkey[i].first<x){
                x = monkey[i].first;
                if(monkey[i].second>y) cnt++,y=monkey[i].second;
            }
        }

        printf("%d\n",cnt);
    }
    return 0;
}
