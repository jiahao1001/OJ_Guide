#include<iostream>
#include<stdio.h>
#include<math.h>
#include<map>
#include<utility>
#include<stdlib.h>
#include<float.h>
using namespace std;
typedef pair<int,int> PII;

int gcd(int a,int b){
  if(!b) return a;
  return gcd(b,a%b);
}
double dist(double x,double y){
  return sqrt(x*x+y*y);
}
int dx,dy;
int L,W,CX,CY,TX,TY,N;
PII get_ball(int i,int j){
  int x,y;
  if(i%2==0) x = dx+i*L;
  else{
    if(i>0) x = dx+(i-1)*L+2*(L-CX-dx);
    else x = dx + (i+1)*L - 2*(CX+dx);
  }
  if(j%2==0) y = dy+j*W;
  else{
    if(j>0)  y = dy+(j-1)*W + 2*(W-CY-dy);
    else y = dy+(j+1)*W - 2*(CY+dy);
  }
  return make_pair(x,y);
}
int main(){

  while(scanf("%d%d%d%d%d%d%d",&L,&W,&CX,&CY,&TX,&TY,&N),L+W+CX+CY+TX+TY+N){
    map<PII,pair<PII,int> > first_hit;
    dx = TX-CX, dy = TY-CY;
    int x,y;

    for(int i=-N;i<=N;i++){
      int j = N-abs(i);
      for(int c=0;c<2;c++){
        PII p = get_ball(i,j);
        x = p.first, y = p.second;
        int g = gcd(abs(x),abs(y));
        PII k = make_pair(x/g,y/g);
        first_hit[k] = make_pair(make_pair(x,y),N);
        if(!j) break;
        j = -j;
      }
    }

    for(int i=-N;i<=N;i++)
      for(int j=-N;j<=N;j++){
        int hits = abs(i)+abs(j);
        if(hits>=N) continue;
        PII p = get_ball(i,j);
        x = p.first, y = p.second;
        int g = gcd(abs(x),abs(y));
        PII k = make_pair(x/g,y/g);
        //double k = atan2(1.0*y,1.0*x);
        if(first_hit.count(k) && hits<first_hit[k].second) first_hit[k] = make_pair(make_pair(x,y),hits);

      }
    double best = DBL_MAX;
    for(map<PII,pair<PII,int> >::iterator it = first_hit.begin();it!=first_hit.end();it++){
      if(it->second.second == N) best = min(best, dist(it->second.first.first,it->second.first.second));
    }
    printf("%.3f\n",best);
  }
}
