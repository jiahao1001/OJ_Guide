#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int front[25][2],back[25][2];
void print(int x){
    if(x<=n)printf(" %d",x);
    else printf(" Blank");
}
int main()
{
    while(scanf("%d",&n),n){
        printf("Printing order for %d pages:\n",n);
        int tot = n;
        while(tot%4) tot++;
        front[0][1] = 1;
        back[0][0] = 2;
        back[0][1] = tot-1;
        front[0][0] = tot;
        int x = 2, y = tot-1;
        int p=0;
        while(true){
            front[p][1] = x-1;
            back[p][0] = x;
            back[p][1] = y;
            front[p][0] = y+1;
            if(x+1==y) break;
            x+=2,y-=2;
            p++;
        }
        for(int i=0;i<=p;i++){
            printf("Sheet %d, front:",i+1);
            print(front[i][0]),printf(","), print(front[i][1]),printf("\n");
            if(back[i][0]>n && back[i][1]>n) continue;
            printf("Sheet %d, back :",i+1);
            print(back[i][0]),printf(","), print(back[i][1]),printf("\n");
        }
        
    }
    return 0;
}
