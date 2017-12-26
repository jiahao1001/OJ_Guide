#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
char letters[26];
int L,C;
char passowrd[30];
bool check(char *s){
    int vowel = 0, consonant = 0;
    for(int i=0;i<L;i++){
        if(string("aeiou").find_first_of(s[i])!=-1) vowel ++;
        else consonant ++;
    }
    return vowel>=1 and consonant>=2;
}
void dfs(int i,int last){
    if(i==L){
        passowrd[L] = 0;
        if(check(passowrd))
            cout<<passowrd<<endl;
        return;
    }
    for(int j = last+1;j<C;j++){
        passowrd[i] = letters[j];
        dfs(i+1,j);
    }
}
int main()
{
    cin>> L >> C;
    for(int i=0;i<C;i++)
        cin>>letters[i];
    sort(letters,letters+C);
    dfs(0,-1);
    return 0;
}
