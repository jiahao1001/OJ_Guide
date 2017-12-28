#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char words[100][120];
char sub[120];
char rev[120];
int n;
int check(int s,int t)
{
    for(int i=0;i<t-s;i++)
        sub[i]=rev[t-s-1-i]=words[0][s+i];
    sub[t-s]=rev[t-s]='\0';
    //cout<<sub<<endl;
    for(int i=0;i<n;i++)
        if(!strstr(words[i],sub) &&!strstr(words[i],rev)) return 0;
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",words[i]);
        int len=strlen(words[0]);
        int i;
        for(i=len;i>=1;i--)
        {
            for(int j=0;j+i-1<len;j++)
                if(check(j,j+i)) goto success;
        }
        printf("0\n");
        continue;
    success:
        printf("%d\n",i);
    }
    return 0;
}
