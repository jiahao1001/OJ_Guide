#include <stdio.h>

int main(){

    int chip[20][20];
    int n,i,j;
    scanf("%d",&n);
    bool good[20];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&chip[i][j]);
        }
    }

    int count;
    for(j=0;j<n;j++){
        count=0;
        for(i=0;i<n;i++){
            count+=chip[i][j];
        }
        if((count-1)>=(n-1)/2) good[j]=true;
        else good[j]=false;
    }

    for(i=0;i<n;i++)
        if(good[i])printf("%d ",i+1);



    return 0;
}