#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char name[100000][1005];
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    
    char a[1005];
    scanf("%s",a);

    for(i=0;i<n;i++){
        scanf("%s",name[i]);
        for(j=0;j<i;j++){
            if(strcmp(name[j],name[i])>0){
                char *temp=(char*)malloc(1005);
                strcpy(temp,name[i]);
                for(k=i;k>j;k--){
                    strcpy(name[k],name[k-1]);
                }
                strcpy(name[j],temp);
                break;
            }
        }
    }


    for(i=0;i<n-1;i++){
        if(strcmp(a,name[i])==0){
            printf("%s",name[i+1]);
            return 0;
        }
    }

    printf("The End");

    




    return 0;
}