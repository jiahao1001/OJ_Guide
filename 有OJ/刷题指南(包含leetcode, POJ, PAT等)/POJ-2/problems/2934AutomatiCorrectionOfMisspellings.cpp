#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int n,q;
char word[10000][30];
set<string> all;
int len[10000];
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%s",word[i]);
    len[i] = strlen(word[i]);
    all.insert(word[i]);
  }
  scanf("%d",&q);
  char w[30];
  while(q--){
	scanf("%s",w);
    int l = strlen(w);
    if(all.find(w)!=all.end()) printf("%s is correct\n",w);
    else{
      int i = 0;
      for(i=0;i<n;i++){
        if(abs(l-len[i])>1) continue;
        int j=0;
        for(j=0;j<l && j<len[i];j++)
          if(w[j]!=word[i][j]) break;
        bool found = false;
        if(l>len[i]) {
          if(strcmp(w+j+1,word[i]+j)==0) found = true;
        }else if(l<len[i]){
          if(strcmp(w+j,word[i]+j+1)==0)  found =true;
 
        }else{
         //equal ,wrong 1 , or exchange
          if(strcmp(w+j+1,word[i]+j+1)==0 || (strcmp(w+j+2,word[i]+j+2)==0 && w[j]==word[i][j+1] && w[j+1]==word[i][j])) found = true;
        }
        if(found){
           printf("%s is a misspelling of %s\n",w,word[i]);
           break;
        }
	  }
      if(i==n) printf("%s is unknown\n",w);
    }
  }
  return 0;    
}
