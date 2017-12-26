#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int tb[10] = {126,48,109,121,51,91,95,112,127,123};
int n;
int seq[10];
char s[20];
bool match(int x){
    int bad = 0;
    for(int i=x,j=0;j<n;j++,i--){
        if((tb[i]&seq[j])!=seq[j]) return false;
        if(bad & seq[j]) return false;
        bad |= (tb[i]^seq[j]);
    }
    return true;
}
int main()
{
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            scanf("%s",s);
            int t = 0;
            for(int j=0;j<7;j++)
                t = t*2 + (s[j]=='Y'?1:0);
            seq[i] = t;
        }
        bool ok = false;
        for(int x=9;x+1>=n;x--)
            if(match(x)) {
                ok = true;
                break;
            }
        
        if(ok) printf("MATCH\n");
        else printf("MISMATCH\n");
    }
    return 0;
}
