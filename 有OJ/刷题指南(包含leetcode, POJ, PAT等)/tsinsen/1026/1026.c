#include <cstdio>

#include<cstring>
using namespace std;

int main(){
    int a[126];
    memset(a,0,sizeof(a));
    char s[110];
    scanf("%s",s);
    int len=strlen(s);
    for(int i=0;i<len;i++) a[s[i]]++;
    for(int i='a';i<='z';i++)
        if(a[i]!=0)
            printf("%c %d\n",i,a[i] );


    return 0;
}