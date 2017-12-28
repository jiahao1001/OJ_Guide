#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int N;
const int MAXN = 20010;
int k[MAXN];
long long lsum[MAXN],rsum[MAXN];
struct Cow{
  int v,x;
} cows[MAXN];
bool operator<(const Cow& c1,const Cow &c2){
  return c1.x<c2.x;
}
bool cmp(const int& a,const int& b){
  return cows[a].v>cows[b].v;
}
long long A[MAXN], B[MAXN]; // A to 2000, B to 0
long long AA[MAXN],BB[MAXN];
inline int lb(int x){
  return x&(-x);
}
void add(int i,long long d,long long *A){
  while(i<=20000){
    A[i] += d;
    i+=lb(i);
  }
}
long long sum(int i, long long* A){
  long long s=0;
  while(i){
    s+=A[i];
    i-=lb(i);
  }
  return s;
}
int main()
{
  scanf("%d",&N);
  lsum[0] = 0;
  for(int i=1;i<=N;i++){
    scanf("%d%d",&cows[i].v,&cows[i].x);
  }
  sort(cows+1,cows+N+1);
  for(int i=1;i<=N;i++){
    lsum[i] = lsum[i-1] + 20000 - cows[i].x;
  }
  rsum[N+1] = 0;
  for(int i=N;i>=1;i--) rsum[i] = rsum[i+1] + cows[i].x;
  for(int i=0;i<N;i++) k[i] = i+1;
  sort(k,k+N,cmp);
  long long moo = 0;
  for(int i=0;i<N;i++){
    int j = k[i];
    long long v = cows[j].v;
    long long x = cows[j].x;
    moo += v*(lsum[j-1] - (j-1)*(20000-x));
    moo += v*(rsum[j+1] - (N-j)*x);
    moo -= v*(sum(j-1,A)-sum(j-1,AA)*(20000-x));
    moo -= v*(sum(N,B)-sum(j,B)-(sum(N,AA)-sum(j,AA))*x);
    add(j,20000-x,A);
    add(j,1,AA);
    add(j,x,B);
    //    printf("%d,%d->%lld\n",i+1,j,moo);
  }
  printf("%lld\n",moo);
  return 0;
}
