#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
char text[10][11];
char msg[110],keyword[12];
int main()
{
    while(scanf("%s",keyword),strcmp(keyword,"THEEND")){
        memset(text,'\0',sizeof text);
        scanf("%s",msg);
        int r = strlen(msg)/strlen(keyword);
        int cnt = strlen(keyword);
        int c = 0;
        for(char ch = 'A';ch<='Z';ch++){
            for(int i=0;i<cnt;i++){
                if(keyword[i]==ch){
                    for(int j=0;j<r;j++) text[j][i]=msg[c*r+j];
                    c++;
                }
            }
        }
        for(int i=0;i<r;i++) printf("%s",text[i]);
        printf("\n");
    }
    return 0;
}
