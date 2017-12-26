#include <stdio.h>
#include <stdlib.h>

long abs(long a){
    return a>=0?a:-a;
}

int cmp(const void *a, const void *b){
    return *(int*)a-*(int*)b;
}

int main(){
    long a[1001], b[1000];
    int n,i,flag=1;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }

    for(i=0;i+1<n;i++)
        b[i]=abs(a[i]-a[i+1]);

    qsort(b,n-1,sizeof(long),cmp);

    for(i=0;i<n-1;i++)
        if(b[i]!=i+1){
            flag=0;
            break;
        }

    if(flag==0)
        printf("I'm unhappy!!\n");
    else
        printf("I'm happy!!\n");



}