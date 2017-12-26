/*
多项分布公式：
P(X1=n1,...,XK=nk)={n! 连乘(i=1~k)[pi^ni/ni!]}
本题ni的取值范围为从0~12，所以计算出ni!保存入数组，随时取用。
分数的可能情况共有：10*12-7*12=36种；分数最大为120
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

double fs[2][130];
double p[2][4];
double conbine[13];

int main(){

    memset(fs,0,sizeof(fs));

    int i,j,x[5];
    double p1,p2;

    conbine[0]=1;
    for(i=1;i<=12;i++){
        conbine[i]=conbine[i-1]*i;
    }

    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            scanf("%lf",&p[i][j]);
        }
    }

    for(x[1]=0;x[1]<=12;x[1]++)
        for(x[2]=0;x[2]<=12-x[1];x[2]++) 
            for(x[3]=0;x[3]<=12-x[1]-x[2];x[3]++) { 
                x[4]=12-x[1]-x[2]-x[3]; 
                p1=p2=conbine[12];
                for(i=1;i<=4;i++){
                    p1=p1*pow(p[0][i-1],x[i])/conbine[x[i]];
                    p2=p2*pow(p[1][i-1],x[i])/conbine[x[i]];
                }
                fs[0][x[1]*7+x[2]*8+x[3]*9+x[4]*10]+=p1; 
                fs[1][x[1]*7+x[2]*8+x[3]*9+x[4]*10]+=p2; 
            }

    for(i=1;i<=3;i++) { 
        int q; 
        double ans=0.0; 
        scanf("%d",&q); 
        for(j=84;j<=120;j++) 
            if(j-q>=84&&j-q<=120) 
                ans+=fs[0][j]*fs[1][j-q]; 
        ans*=100.0; 
        printf("%.0lf%%\n",ans); 
    } 


    return 0;
}

