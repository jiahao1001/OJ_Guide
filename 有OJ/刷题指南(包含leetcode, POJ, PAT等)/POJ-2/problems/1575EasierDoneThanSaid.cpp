#include<iostream>
#include<string.h>
using namespace std;
char s[30];
int cnt[26];
inline int get_cnt(char c){
    return cnt[c-'a'];
}
inline int isVowels(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int main()
{
    bool one_vowel,no_three_vowels, no_three_consonants,no_same_letter;
    while(scanf("%s",s),strcmp(s,"end"))
    {
        memset(cnt,0,sizeof(cnt));
        int n=strlen(s);
        for(int i=0;i<n;i++)
            cnt[s[i]-'a']++;
        
        if(get_cnt('a') || get_cnt('e') || get_cnt('i') || get_cnt('o')||get_cnt('u'))
            one_vowel=true;
        else one_vowel=false;
        
        no_same_letter=true;
        for(int i=0;i<n-1;i++)
            if(s[i]==s[i+1] && s[i]!='e' && s[i]!='o') no_same_letter=false;
        
        no_three_vowels=true;
        no_three_consonants=true;
        for(int i=0;i<=n-3;i++)
        {
            if(isVowels(s[i]) && isVowels(s[i+1]) &&isVowels(s[i+2])) no_three_vowels=false;
            if(!isVowels(s[i])&& !isVowels(s[i+1]) &&!isVowels(s[i+2])) no_three_consonants=false;
        }
        
        
        
        if(one_vowel && no_three_vowels && no_three_consonants && no_same_letter)
            printf("<%s> is acceptable.\n",s);
        else printf("<%s> is not acceptable.\n",s);
        
    }
}
