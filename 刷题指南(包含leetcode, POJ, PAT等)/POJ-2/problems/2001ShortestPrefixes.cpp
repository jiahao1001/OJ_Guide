#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct Nd{
    int cnt;
    Nd *next[26];
    Nd(){
        cnt=0;
        for(int i=0;i<26;i++) next[i]=NULL;
    }
};
void insert(Nd *r,char *word)
{
    int len=strlen(word);
    for(int i=0;i<len;i++){
        if(!r->next[word[i]-'a']){
            r->next[word[i]-'a']=new Nd();
        }
        r=r->next[word[i]-'a'];
        r->cnt++;
    }
}
char abbr[25];
char *query(Nd *r,char *word)
{
    int i=0;
    int len=strlen(word);
    for(i=0;i<len;i++)
    {
        r=r->next[word[i]-'a'];
        abbr[i]=word[i];
        if(r->cnt==1) break;
    }
    if(i==len) abbr[i]='\0';
    else abbr[i+1]='\0';
    return abbr;
}
char words[10000][24];
int cnt;
int main()
{
    Nd *trie=new Nd();
    while(scanf("%s",words[cnt++])!=EOF)
    {
        insert(trie,words[cnt-1]);
    }
    for(int i=0;i<cnt;i++)
        printf("%s %s\n",words[i],query(trie,words[i]));
    return 0;
}
