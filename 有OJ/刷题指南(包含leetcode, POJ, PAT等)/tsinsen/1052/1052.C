#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *pinyin[11]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","shi"};
int main(){
    char num[11];
    
    scanf("%s",num);

    int len=strlen(num);
    int part=len/4;
    int i=len%4;
    int index=0;
    int j;
    bool flag=false; //是否万位全是0

    if(len==1){
        printf("%s", pinyin[num[index]-'0']);
        return 0;
    }
    if(len>8){
        if(num[len-5]-'0'==0&&num[len-6]-'0'==0&&num[len-7]-'0'==0&&num[len-8]-'0'==0)
            flag=true;
    }

    bool flagzero=false,flagten=false; //是否都是0，10前面是不是有数字，是否有非0数

    //先读第一部分不够4位的
    for(;i>0;i--,index++){
        if(num[index]-'0'==0){
            flagzero=true;
        }else{
            if(i==4){
                printf("%s qian ", pinyin[num[index]-'0']);
                flagten=true;
            }
            if(i==3){
                if(flagzero){
                    printf("ling ");
                    flagzero=false;
                }
                printf("%s bai ", pinyin[num[index]-'0']);
                flagten=true;
            }
            if(i==2){
                if(flagzero){
                    printf("ling ");
                    flagzero=false;
                }
                if(num[index]=='1'){
                    if(flagten==false)
                        printf("shi ");
                    else
                        printf("yi shi ");
                }
                else 
                    printf("%s shi ", pinyin[num[index]-'0']);
            } 
            if(i==1){
                if(flagzero){
                    printf("ling ");
                    flagzero=false;
                }
                if(num[index]-'0'!=0)
                    printf("%s ", pinyin[num[index]-'0']);
            }
        }
    }
    if(len%4){
        if(part==1)printf("wan ");
        if(part==2)printf("yi ");
    }

    for(j=part;j>0;j--){
        flagten=false;
        for(i=4;i>0;i--,index++){
            if(num[index]-'0'==0){
                flagzero=true;
            }else{
                if(i==4){
                    if(flag){
                        printf("ling ");
                    }
                    printf("%s qian ", pinyin[num[index]-'0']);
                    flagten=true;
                    flagzero=false;
                }
                if(i==3){
                    if(flagzero){
                        printf("ling ");
                        flagzero=false;
                    }
                    printf("%s bai ", pinyin[num[index]-'0']);
                    flagten=true;
                }
                if(i==2){
                    if(flagzero){
                        printf("ling ");
                        flagzero=false;
                    }
                    printf("%s shi ", pinyin[num[index]-'0']);
                } 
                if(i==1){
                    if(flagzero){
                        printf("ling ");
                        flagzero=false;
                    }
                    if(num[index]-'0'!=0)printf("%s ", pinyin[num[index]-'0']);
                }
            }
        }
        if(j==2&&!flag)printf("wan ");
        if(j==3)printf("yi ");
    }



    return 0;
}