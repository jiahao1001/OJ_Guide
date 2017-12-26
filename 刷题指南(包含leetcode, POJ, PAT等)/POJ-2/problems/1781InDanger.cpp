
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int f(int x){
    if(!x) return 1;
    return 10*f(x-1);
}
int main(){
    int a,e;
    while(scanf("%de%d",&a,&e)){
        if(!a && !e) break;
        a*=f(e);
        int x = 0;
        e = a;
        while(e) x++,e>>=1;
        printf("%d\n",(a<<1)-(1<<x)+1);
    }
    return 0;
}
