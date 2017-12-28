#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
struct Rect{
	int x1,y1,x2,y2,id;
	Rect(){
		x1 = y1 = 1000000;
		x2 = y2 = 1;
		id = -1;
	}
} rects[26];
bool cmp_x(const Rect& r1,const Rect& r2){
	return r1.x1<r2.x1;
}
bool cmp_y(const Rect& r1,const Rect& r2){
	return r1.y1<r2.y1;
}
int main()
{
	int t,k,p,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&k,&p);
		for(int i=0;i<k;i++) rects[i] = Rect();
		int cnt = -1;
		for(int i=0;i<k;i++)
			for(int j=0;j<p;j++){
				scanf("%d%d",&x,&y);
				rects[i].x1 = min(x,rects[i].x1);
				rects[i].x2 = max(x,rects[i].x2);
	            rects[i].y1 = min(y,rects[i].y1);
				rects[i].y2 = max(y,rects[i].y2);
			}
		sort(rects,rects+k,cmp_x);
		x = -1;
		for(int i=0;i<k;i++){
			if(rects[i].x1>x) rects[i].id = ++cnt;
			else rects[i].id = cnt;
			x = max(x,rects[i].x2); 
		}
		sort(rects,rects+k,cmp_y);
		y = -1;
		bool ans = true;
		for(int i=0;i<k;i++){
			if(rects[i].y1<=y){
				if(i>0 && rects[i-1].id==rects[i].id) ans =false;
			}
			y = max(y,rects[i].y2);
		}
		if(ans)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
