#include <stdio.h>
#include <string.h>

#define MAXLEN 21

int main(){
    char a[MAXLEN],ans[MAXLEN],A[MAXLEN];
    scanf("%s",a);
    int n, i, j, diff, hasans=0, lenA, lena;
    lena=strlen(a);
    scanf("%d",&n);


    for(i=0;i<n;i++){
        scanf("%s",A);
        if(!strcmp(a,A)){
            printf("%s",A);
            return 0;
        }

        if(!hasans){
            lenA=strlen(A);
            diff=0;

            if(lena==lenA){
                //如果长度相同，则只能有一处不同
                for(j=0;j<lena;++j){
                    if(a[j]!=ans[j])
                        diff++;
                }
                if(diff<=1){
                    strcpy(ans,A);
                    hasans=1;
                }
            }
            else if(lena==lenA+1){
                //如果a比A长
                diff=0;
                int j=0;
                while(a[j]==A[j])
                    ++j;
                while(j<lenA){
                    if(A[j]!=a[j+1]){
                        ++diff;
                        break;
                    }
                    ++j;
                }
                if(diff==0){
                    strcpy(ans,A);
                    hasans=1;
                }
            }
            else if(lenA==lena+1){
                //如果A比a长
                diff=0;
                int j=0;
                while(a[j]==A[j])
                    ++j;
                while(j<lenA){
                    if(a[j]!=A[j+1]){
                        ++diff;
                        break;
                    }
                    ++j;
                }
                if(!diff){
                    strcpy(ans,A);
                    hasans=1;
                }
            }
            
        }
    }

    if(!hasans) printf("NOANSWER");
    else printf("%s", ans);
    return 0;
}