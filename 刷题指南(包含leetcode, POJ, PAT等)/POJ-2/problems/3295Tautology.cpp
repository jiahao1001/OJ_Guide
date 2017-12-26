#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
char formula[120];
int split[120][120];
int legal[120][120];
int isLegal(int s,int t)
{
    if(t<=s) return 0;
    if(legal[s][t]!=-1) return legal[s][t];
    if(t-s==1){
        return legal[s][t]=(formula[s]=='p'||formula[s]=='q'||formula[s]=='r'||formula[s]=='s'||formula[s]=='t')?1:0;
    }
    if(formula[s]=='N') return legal[s][t]=isLegal(s+1,t);
    if(formula[s]=='K'||formula[s]=='A'||formula[s]=='C'||formula[s]=='E'){
        for(int k=s+2;k<t;k++){
            if(isLegal(s+1,k)&&isLegal(k,t)) {
                split[s][t]=k;
                return legal[s][t]=1;
            }
        }
    }
    return legal[s][t]=0;
}
int getValue(int s,int t,map<char,int> &val)
{
    int k;
    if(t-s==1) return val[formula[s]];
    if(formula[s]=='N') return getValue(s+1,t,val)^1;
    if(formula[s]=='K'){
        k=split[s][t];
        return getValue(s+1,k,val)&getValue(k,t,val);
    }
    if(formula[s]=='A'){
        k=split[s][t];
        return getValue(s+1,k,val)|getValue(k,t,val);
    }
    if(formula[s]=='C'){
        k=split[s][t];
        return (1-getValue(s+1,k,val)) |getValue(k,t,val);
    }
    if(formula[s]=='E'){
        k=split[s][t];
        return getValue(s+1,k,val)==getValue(k,t,val)?1:0;
    }
    
}
int main()
{
    while(scanf("%s",formula),formula[0]!='0')
    {
        memset(legal,-1,sizeof(legal));
        int len=strlen(formula);
        isLegal(0,len);
        int i;
        for(i=0;i<(1<<5);i++){
            map<char,int> val;
            val['p']=(i>>0)&1;
            val['q']=(i>>1)&1;
            val['r']=(i>>2)%1;
            val['s']=(i>>3)&1;
            val['t']=(i>>4)&1;
            if(!getValue(0,len,val)){
                printf("not\n");
                break;
            }
        }
        if(i==(1<<5)) printf("tautology\n");
    }
    return 0;
}
