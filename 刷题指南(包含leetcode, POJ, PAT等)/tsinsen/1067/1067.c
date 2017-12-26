#include <stdio.h>

long long fi[10001];

int main(){
    int s,t;
    scanf("%d %d",&s,&t);
    int a,b,c,d,i;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    fi[0]=0;fi[1]=1;
    long long tt=a*b*c*d;
    for(i=2;i<=t;i++){
        fi[i]=fi[i-1]%tt+fi[i-2]%tt;   //此处为重点
    }
    for(i=s;i<=t;i++){
        if(s==1||s==2){
            if(1%a!=0&&1%b!=0)
        }
        if(fi[i]%a!=0&&fi[i]%b!=0&&fi[i]%c!=0&&fi[i]%d!=0){
            printf("%d ",i);   //测试点9始终无法通过，未找到原因；s==2时必须输出1，s==1时才输出1，2；未找到原因
        }
    }
    return 0;
}