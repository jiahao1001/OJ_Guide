#include <stdio.h>


int main(){
    int v1,v2,t,s,l;
    scanf("%d %d %d %d %d",&v1,&v2,&t,&s,&l);
    int tt=0;
    int lt=0,lr=0;
    bool flag=false;
    int count=0;


    while(lt<l&&lr<l){
        if(!flag){
            if(lr-lt>=t){
                flag=true;
                count=0;
            }
        }

        if(flag){
            count++;
            if(count==s){
                flag=false;
            }
        }else{
            lr+=v1;
        }
        lt+=v2;
        tt++;
    }

    if(lt==lr){
        printf("D\n%d",tt);
    }else if(lt==l){
        printf("T\n%d",tt);
    }else {
        printf("R\n%d",tt);
    }



    return 0;
}