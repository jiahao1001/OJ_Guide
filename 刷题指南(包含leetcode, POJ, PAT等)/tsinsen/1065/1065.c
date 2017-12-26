#include <stdio.h>



double vt[4],vr[4],li[1010],t,tx,rx;  //vt,vr为乌龟和兔子的速度；li为各路段的长度；tx为乌龟还有多长时间减速，rx为兔子还有多长时间减速
double tt=0,tr=0,l1,l2; //tt，tr为乌龟和兔子用的时间；j1,j2为乌龟，兔子的当前减速状况；l1，l2为乌龟和兔子的当前路段的剩余长度
int n,i,ti[1010],j1=10,j2=10;  //ti为路段类型

void js(int xx) 
{  
    if(xx==1){if(j1>1){j1-=1;}} 
    else {if(xx==2)if(j2>1){j2-=1;}}    //这里必须是大于0.2 而不是大于0.1，为什么？
                                        //浮点数的精度问题
}

int main(){
    
    scanf("%d %lf",&n,&t);tx=rx=t;
    scanf("%lf %lf %lf %lf",&vt[0],&vt[1],&vt[2],&vt[3]);
    scanf("%lf %lf %lf %lf",&vr[0],&vr[1],&vr[2],&vr[3]);
    for(i=0;i<n;i++){
        scanf("%d %lf",&ti[i], &li[i]);
    }
    for(i=0;i<n;i++){
        l1=li[i];
        int type=ti[i];
        double v=vt[type-1];

        while(1){
            if(l1/(v*j1/10.0)<=tx){
                tx-=l1/(v*j1/10.0);
                tt+=l1/(v*j1/10.0);
                break;
            }else{
                tt+=tx;
                l1-=(v*j1/10.0)*tx;
                tx=t;
                js(1);
            }
        }

    }

    for(i=0;i<n;i++){
        l2=li[i];
        int type=ti[i];
        double v=vr[type-1];

        while(1){
            if(l2/(v*j2/10.0)<=rx){
                rx-=l2/(v*j2/10.0);
                tr+=l2/(v*j2/10.0);
                break;
            }else{
                tr+=rx;
                l2-=(v*j2/10.0)*rx;
                rx=t;
                js(2);
            }
        }
    }

    if(tt==tr){
        printf("D\n%.2lf",tt);
    }else if(tt>tr){
        printf("R\n%.2lf",tr);
    }else{
        printf("T\n%.2lf",tt);
    }
    return 0;

}