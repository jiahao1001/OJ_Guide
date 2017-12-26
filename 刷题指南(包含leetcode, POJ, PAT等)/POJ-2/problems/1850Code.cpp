#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char w[20];
    int c[27][27];
    c[1][0]=c[1][1]=1;
    for(int i=2;i<=26;i++)
        for(int j=0;j<=i;j++)
            if(!j || j==i) c[i][j]=1;
            else c[i][j]=c[i-1][j]+c[i-1][j-1];
    scanf("%s",w);
    int len=strlen(w);
    int i;
    for(i=1;i<len;i++)
        if(w[i]<=w[i-1]) break;
    if(i<len){
        printf("0\n");
        return 0;
    }
    int sum=0;
    for(int i=1;i<len;i++)
        sum+=c[26][i];
    char str;
    for(str='a';str!=w[0];str++)
        sum+=c['z'-str][len-1];
    for(int i=1;i<len;i++)
    {
        for(str=w[i-1]+1;str!=w[i];str++)
            sum+=c['z'-str][len-1-i];
    }
    printf("%d\n",sum+1);
    return 0;
}
