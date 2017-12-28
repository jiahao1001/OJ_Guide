#include <stdio.h>
#include <string.h>


int main(){
    int a[201][201];
    bool flag[201][201];
    int m,n,i,j,c=1;;
    scanf("%d %d",&m,&n);
    memset(a,0,sizeof(flag));

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            flag[i][j]=true;
        }
    }


    i=0;j=0;c=0;
    while(c<m*n-1){
        while(flag[i+1][j]){
            printf("%d ",a[i++][j]);
            c++;
            flag[i-1][j]=false;
        }
        while(flag[i][j+1]){
            printf("%d ",a[i][j++]);
            c++;
            flag[i][j-1]=false;
        }
        while(i-1>=0&&flag[i-1][j]){
            printf("%d ",a[i--][j]);
            c++;
            flag[i+1][j]=false;
        }
        while(j-1>=0&&flag[i][j-1]){
            printf("%d ",a[i][j--]);
            c++;
            flag[i][j+1]=false;
        }
    }
    printf("%d", a[i][j]);


    return 0;

}