#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<utility>
#include<queue>
#include<limits.h>
#include<set>
#include<ctype.h>
using namespace std;

char s[100];
char t[100],cnt;
int mark[100];
int main()
{
    gets(s);
    int len = strlen(s);
    set<char> v;
    v.insert('A');
    v.insert('E');
    v.insert('I');
    v.insert('O');
    v.insert('U');
    bool space = true;
    int cnt = 0;
    for(int i=0;i<len;i++){
        if(isalpha(s[i])) {
            if(!v.count(s[i])) v.insert(s[i]), t[cnt++]=s[i], space = false;
        }else {
            if(s[i]==' '){
                if(!space) space = true, t[cnt++] = ' ';//putchar(' ')
            }else{
                space = false, t[cnt++] = s[i];
            }
        }
    }
    for(int i=cnt-1;i>=0;i--)
        if(t[i]!=' '){
            cnt = i+1;
            break;
        }
    for(int i=0;i<cnt;i++)
        if(t[i]==' ' && !isalpha(t[i+1])) mark[i] = 1;
    for(int i=0;i<cnt;i++) if(!mark[i]) putchar(t[i]);
    putchar('\n');
    return 0;
}
