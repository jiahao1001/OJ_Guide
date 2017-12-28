#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
#include<string>
using namespace std;
char s[10000000];
char t[10000000];
int len;
int main()
{
    while(gets(s)){
        len = 0;
        string distinct="";
        int cnt=0;
        int i=0;
        int n  = strlen(s);
        int start;
        while(i<n){
            cnt = 1;
            while(cnt<9 && i+1<n && s[i]==s[i+1]) i++,cnt++;
            if(cnt!=1) t[len++] = char('0'+cnt), t[len++] = s[i];
            if(cnt!=1) i++;
            if(i==n)break;
            distinct = "";
            start = i;
            while(i+1<n && s[i]!=s[i+1]) i++;
	    if(i+1==n) i++; 
            if(i==start) continue;
            t[len++]='1';
            for(int j=start;j<i;j++){
                if(s[j]=='1') t[len++] = '1', t[len++]='1';
                else t[len++] = s[j];
            }
            t[len++]='1';
        }
        t[len]='\0';
        printf("%s\n",t);
        
    }
    return 0;
}
