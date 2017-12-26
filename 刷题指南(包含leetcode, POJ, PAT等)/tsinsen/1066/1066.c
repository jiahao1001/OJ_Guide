#include <stdio.h>


int c[3001];

int get(int i){
    while(i!=c[i])i=c[i];
    return i;
}

void add(int a, int b){
    int af=get(a);
    int bf=get(b);

    if(af!=bf)c[bf]=af;
}

int main(){
    int n,m,i,a,b,count=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        c[i]=i;
    }
    for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        add(a,b);
    }
    for(i=0;i<n;i++){
        if(i==c[i])count++;
    }
    printf("%d",count);

    return 0;
}