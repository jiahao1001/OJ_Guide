#include <stdio.h>
#include <string.h>

char str[101];

bool check(int i, int j){
    int L=(j-i+1)/2;
    for (int k=i;k<=i+L-1;k++)
        if (str[k]!=str[k+L]) return false;
    return true;
}

int main(){
    scanf("%s",str);

    int len=strlen(str);
    int k=len-len%2;  //必须是偶数
    int i,j;
    for(;k>0;k-=2)
        for(i=0;i<=len-k;i++){
            j=i+k-1;
            if(check(i,j)){
                    printf("%d\n",k);
                return 0;
            }
        }

    printf("%d\n",k);
    return 0;
}