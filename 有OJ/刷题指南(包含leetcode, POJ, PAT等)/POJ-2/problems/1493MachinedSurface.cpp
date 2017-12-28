#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int n;
    char line[30];
    while(scanf("%d",&n),n){
        gets(line);
        int total = 0;
        int m = 0;
        for(int i=0;i<n;i++){
            gets(line);
            int lm = 0;
            for(int j=0;j<25;j++)
                if(line[j]=='X') total++,lm++;
            m = max(m,lm);
        }
        printf("%d\n",n*m-total);
    }

    return 0;
}
