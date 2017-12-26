#include<iostream>
#include<stdio.h>
#define MOD 84673
using namespace std;
char s[16000000];
int n,nc;
int bucket[MOD];
struct T
{
    char w[20];
    int next;
}pool[1600000];
int ELFhash(char *key, int M)
{
    unsigned int h=0;
    while(*key)
    {
        h=(h<<4)+ *key++;
        unsigned int g= h&0xF0000000;
        if(g) h^=g>>24;
        h&=~g;
    }
    return h%M;
}
int ne;
int found(char *w)
{
    char ww[20];
    for(int i=0;i<n;i++)
        ww[i]=w[i];
    ww[n]='\0';
    int h=ELFhash(ww,MOD);
    int i;
    for(i=bucket[h];i!=-1;i=pool[i].next)
    {
        if(!strcmp(ww,pool[i].w)) return 1;
    }
    pool[ne].next=bucket[h];
    strcpy(pool[ne].w,ww);
    bucket[h]=ne;
    ne++;
    
    return 0;
}

int main()
{
    int cnt=0;
    scanf("%d%d",&n,&nc);
    scanf("%s",s);
    int len=strlen(s);
    memset(bucket,-1,sizeof(bucket));
    for(int i=0;i+n-1<len;i++)
    {
        if(!found(s+i)) cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
