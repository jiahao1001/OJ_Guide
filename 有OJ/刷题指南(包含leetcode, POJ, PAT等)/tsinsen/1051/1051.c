#include <stdio.h>
#include <string.h>


char dna[10][100];
int main(){
    char base[4]={'A','C','G','T'};
    int result[100];
    int n,i,j,k,l,m;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%s",dna[i]);
    }

    l=strlen(dna[0]);
    for(j=0;j<l;j++){
        int count[4]={0};
        for(i=0;i<n;i++){
            if(dna[i][j]=='A'){
                count[0]++;
            }
            if(dna[i][j]=='C'){
                count[1]++;
            }
            if(dna[i][j]=='G'){
                count[2]++;
            }
            if(dna[i][j]=='T'){
                count[3]++;
            }
        }
        k=0;
        for(m=1;m<4;m++){
            if(count[m]>count[k])k=m;
        }
        result[j]=base[k];
    }

    for(j=0;j<l;j++){
        printf("%c", result[j]);
    }


    return 0;
}