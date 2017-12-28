#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
using namespace std;
const int N = 40;
int cake[N];
int n;
int flip[2*N];
void reverse(int j){
    for(int i=1;i<j;i++,j--){
        swap(cake[i],cake[j]);
    }
}
int main()
{
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++)
            scanf("%d",cake+i);
        int cnt = 0;
        for(int i=n;i>=1;i--){
            //get the largest
            int id = 0;
            for(int j=1;j<=i;j++){
                if(cake[j]==i) id = j;
            }
            if(id==i)continue;
            else {
                if(id!=1) flip[cnt++] = id, reverse(id);
                flip[cnt++] = i, reverse(i);
            }
        }
        printf("%d",cnt);
        for(int i=0;i<cnt;i++) printf(" %d",flip[i]);
        printf("\n");
    }
    return 0;
}
