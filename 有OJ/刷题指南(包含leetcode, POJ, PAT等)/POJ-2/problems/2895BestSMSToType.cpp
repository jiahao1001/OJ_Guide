#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char s[1010];
int t,p,w;
int pr[27]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4,1};
int d[27]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9,1};
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&p,&w);
        gets(s);
        gets(s);
        int len = strlen(s);
        int last = 1;
        int total = 0;
        for(int i=0;i<len;i++){
            int x;
            if(s[i]==' ') x = 26;
            else x = s[i]-'A';
            total+=pr[x]*p;
            if(last==d[x] && last!=26) total+=w;
            last = d[x];
        }
        printf("%d\n",total);
    }

    return 0;
}
