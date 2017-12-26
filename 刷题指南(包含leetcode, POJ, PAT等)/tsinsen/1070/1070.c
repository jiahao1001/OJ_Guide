#include <stdio.h>

int main(){
    int k,n,a,b,i,j;
    bool ok=false;
    scanf("%d%d",&k,&n);

    printf("f");
    for(i=0;i<k;i++)printf("'");
    printf("(x)=");

    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        for(j=0;j<k;j++){
            a*=b;
            b--;
        }

        if(a!=0){
            if(i!=0&&a>0)printf("+");
            if(a==-1)printf("-");
            else if(a!=1)printf("%d",a);
            ok=true;
        }

        if(a!=0&&b>0){
            if(b==1)printf("*x");
            else printf("*x^%d",b);
            ok=true;
        }
    }

    if(!ok)printf("0");
    return 0;

}