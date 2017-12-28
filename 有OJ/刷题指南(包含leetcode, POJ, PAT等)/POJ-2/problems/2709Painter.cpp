#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
int N;
int v[12],g;
bool good(int x){
  priority_queue<int> Q;
  for(int i=0;i<N;i++){
    if(x*50<v[i]) return false;
    if(x*50-v[i]>0) Q.push(x*50-v[i]);
  }
  int m = 0,a,b,c;
  while(Q.size()>=3){
     a = Q.top(); Q.pop();
     b = Q.top(); Q.pop();
     c = Q.top(); Q.pop();
     m++;
     if(m==g) return true;
     if(a>1)
     Q.push(a-1);
     if(b>1)
     Q.push(b-1);
    if(c>1) Q.push(c-1);
  }
  return m>=g;

}
int main(){
  while(scanf("%d",&N),N){
    for(int i=0;i<N;i++)
      scanf("%d",v+i);
    scanf("%d",&g);
    int ans = 0;
    for(;;ans++){
	if(good(ans)) break;
    }
    printf("%d\n",ans);
}
