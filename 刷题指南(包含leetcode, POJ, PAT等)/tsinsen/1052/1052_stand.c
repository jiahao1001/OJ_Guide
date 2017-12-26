#include<iostream> 
#include<cstdio> 
#include<cstring> 
#include<cstdlib> 

using namespace std; 
char df[][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"}; 
char s[15]; 
int main() 
{ 
    scanf("%s",s); 
    int lens=strlen(s); 
    bool bk=false; 
    for (int i=0;i<lens;i++) 
    { 
        int p,lendf; 
        p=s[i]-'0'; 
        if (p!=0)   //只看p不为0的情况，跳过所有p==0的情况；然后在下面判断p前面如果是0，就输出“ling”
        { 
            bk=false; 
            lendf=strlen(df[p]); 

            if (s[i-1]-'0'==0)  //在这里判断，保证只输出一次ling
               printf("ling "); 

            if ((lens-i)%4==2 && p==1 /*&& s[i-1]-'0'==0  && s[i-2]-'0'==0*/ && i==0) 
            { 
                printf("shi "); 
                continue;   //10打头的时候，不需要读“yi shi”，其他时候，均需要读“yi shi”
            } 

            for (int j=0;j<lendf;j++) 
                printf("%c",df[p][j]);  //这里可以改成用“%s”
            printf(" "); 

            if ((lens-i)%4==2) printf("shi "); 
            if ((lens-i)%4==3) printf("bai "); 
            if ((lens-i)%4==0) printf("qian "); 
        } 
        if ((lens-i)%4==1)   //如果读完这一位后到了分界处
        { 
            if ((lens-i)/4==2)    //如果是“yi”
            { 
                bk=true; 
                printf("yi "); 
            } 
            if (bk==false && (lens-i)/4==1) printf("wan ");   //万的4个位不全是0时，才读“wan”
        } 

    } 
    return 0; 
}