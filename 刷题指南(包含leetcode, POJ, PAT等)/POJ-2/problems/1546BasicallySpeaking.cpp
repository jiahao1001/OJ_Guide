#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <stack>
using namespace std;
char num[10];
int b1,b2;
int ctoi(char c){
    if(c<='9') return c-'0';
    else return c-'A'+10;
}
int itoc(int i){
    if(i<10) return '0'+i;
    else return i-10+'A';
}
char ans[10];
inline int get(){
    int len = strlen(num);
    int n = 0;
    for(int i=0;i<len;i++){
        n = n*b1+ctoi(num[i]);
    }
    return n;
}
inline int convert(int n){
    
    for(int i=6;i>=0 && n;i--){
        ans[i] = itoc(n%b2);
        n/=b2;
    }
    if(n) return -1;
    return 0;
}
int main(){
    while(scanf("%s %d %d",num,&b1,&b2)!=EOF){
        memset(ans,' ',sizeof(ans));
        ans[7]='\0';
        int real = get();
        if(convert(real)==-1){
            printf("  ERROR\n");
        }else{
            
            printf("%s\n",ans);
        }
    }
}
