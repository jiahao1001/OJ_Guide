#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include <set>
using namespace std;
struct P{
	char c;
	int x,y; 
} ps[7];
inline char get_p(char* b,int x,int y){
	return b[x*9+y];
}
bool general(char *b,int x,int y,int bx,int by){
	if(y!=by) return false;
	for(int a=bx+1;a<x;a++)
		if(get_p(b,a,y)!='.') return false;
	return true;
}
int help(char *b,int x,int y,int bx,int by){
	if(x!=bx && y!=by) return -1;
	int cnt = 0;
	if(y==by){
		if(x>bx) swap(x,bx);
		for(int i=x+1;i<bx;i++)
			if(get_p(b,i,y)!='.') cnt++;
	}else if(x==bx){
		if(y>by) swap(y,by);
		for(int i=y+1;i<by;i++)
			if(get_p(b,x,i)!='.') cnt++;
	}
	return cnt;

}
bool cannon(char *b,int x,int y,int bx,int by){
	return help(b,x,y,bx,by)==1;
}
bool chariot(char *b,int x,int y,int bx,int by){
	return help(b,x,y,bx,by)==0;
}
bool horse(char *b,int x,int y,int bx,int by){
	if(abs(x-bx)+abs(y-by)!=3) return false;
	int xd,yd;
	xd = bx-x, yd = by-y;
    if(abs(xd)!=1 && abs(yd)!=1) return false;
	if(abs(xd)==1) xd = 0;
	else xd /=2;
	if(abs(yd)==1) yd = 0;
	else yd/=2;
	return get_p(b,x+xd,y+yd)=='.';
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int main(){
	int n,x,y,a,bb;
	while(scanf("%d%d%d",&n,&x,&y),n){
		x--,y--;
		int rx,ry;
		char b[100];
		memset(b,'.',sizeof(b));
		b[90] = '\0';
		for(int i=0;i<n;i++){
			scanf(" %c%d%d",&ps[i].c,&a,&bb);
            a--,bb--;
			ps[i].x = a, ps[i].y = bb;
			b[a*9+bb] = ps[i].c;
			if(ps[i].c=='G') rx = a,ry=bb;
		}
        // check
	    bool alive = false;
		if(y==ry){
			int a;
			for(a=x+1;a<rx;a++)
				if(get_p(b,a,y)!='.') break;
			if(a==rx) alive = true;
		}
		if(alive){
			printf("NO\n");
			continue;
		}
   
	   int nx,ny;
	   for(int k=0;k<4;k++){
		   nx = x+dx[k], ny = y+dy[k];
		   if(nx<0 || nx>2 || ny<3 || ny>5) continue;
		   char *nb = b;
		   int i;
		   for(i=0;i<n;i++){
			   if(ps[i].x == nx && ps[i].y ==ny) continue;
			   if(ps[i].c=='G'){
				   if(general(nb,ps[i].x,ps[i].y,nx,ny)){
					   break;
				   }   
			   }else if(ps[i].c=='H'){
				   if(horse(nb,ps[i].x,ps[i].y,nx,ny)) {
					   break;
				   }
			   }else if(ps[i].c=='R'){
				   if(chariot(nb,ps[i].x,ps[i].y,nx,ny)) {
					   break;
				   }
			   }else if(ps[i].c=='C'){
				   if(cannon(nb,ps[i].x,ps[i].y,nx,ny)) {
                       break;
				   }
			   }
		   }
		   if(i==n) alive = true;
	   }
       if(alive) printf("NO\n");
	   else printf("YES\n");	
	}	
	return 0;
}
