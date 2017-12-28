#include<iostream>
#include<stdio.h>
using namespace std;
int t;
int p[12];
inline int A(int n,int k){
    int ret = 1;
    for(int i=0;i<k;i++)
        ret*=(n-i);
    return ret;
}
int main(){
    scanf("%d",&t);
    int n,k;
    for(int q=1;q<=t;q++){
        scanf("%d%d",&n,&k);
        for(int i=0;i<k;i++) scanf("%d",p+i);
        int m = 0;
        m+=(p[0]-1)*A(n-1,k-1);
        for(int i=1;i<k;i++){
            int a,b;
            a=b=0;
            for(int j=0;j<i;j++)
                if(p[j]<p[i]) a++;
                else b++;
            m+=(p[i]-1-a)*A(n-1-i, k-1-i);
        }
        printf("Variace cislo %d ma poradove cislo %d.\n",q,m+1);
    }
    return 0;
}
