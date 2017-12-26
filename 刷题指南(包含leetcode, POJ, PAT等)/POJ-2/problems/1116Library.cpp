#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 100;
struct Shelf{
    int y,x1,x2,px1,px2;
} shelves[N];
int niche_w,niche_h,tome_w,tome_h;
int pegs_removed, cut;
int n;
int l_cut;
int move(const Shelf &s, int d){
    //return 1, if need to move a peg
    int x1 = s.x1, x2 = s.x2;
    x1+=d, x2+=d;
    int px1 = s.px1, px2 = s.px2;
    l_cut = 0;
    if(x1+x2>2*px2) l_cut = x1+x2-2*px2;
    if(x1+x2<2*px1) l_cut = 2*px1-x1-x2;
    if(x1<0) l_cut = max(l_cut,-x1);
    if(x2>niche_w) l_cut = max(l_cut,x2-niche_w);
    if(2*px1<=x1+x2 && x1+x2<=2*px2) return 0;
    else return 1;
}
int cut_shelf_left(const Shelf& s,int x){
    int l = s.x2-s.x1;
    int x2 = min(niche_w,s.px2+l);
    int x1 = x2-l;
    return max(0,x-x1);
}
int cut_shelf_right(const Shelf& s,int x){
    int l = s.x2-s.x1;
    int x1 = max(0,s.px1-l);
    int x2 = x1+l;
    return max(0,x2-x);
}
void clear_rectangle(int x1,int x2,int y1,int y2,int p){
    int pegs = p, shorten = 0;
    
    for(int i=0;i<n;i++){
        
        // 1. leave the shelf on its original place
        if(shelves[i].y<=y1 || shelves[i].y>=y2) continue;
        if(shelves[i].x2<=x1 || shelves[i].x1>=x2) continue;
        
        // 6. if peg is between, must remove two pegs and shelf
        if(shelves[i].px1>x1 && shelves[i].px2<x2){
            pegs += 2;
            shorten += shelves[i].x2-shelves[i].x1;
            continue;
        }
        int this_cut = INT_MAX;
        int this_peg = INT_MAX;
        int yes = 0;
        if(shelves[i].px2>x1 && shelves[i].px1<=x1){
            yes = 1;
            int cc = 0;
            if(x1==0) yes = 2, cc = shelves[i].x2-shelves[i].x1;
            else cc= cut_shelf_right(shelves[i],x1);
            if(yes<this_peg) this_peg = yes, this_cut = cc;
            else if(yes==this_peg) this_cut = min(cc,this_cut);
        }
        if(shelves[i].px1<x2 && shelves[i].px2>=x2){
            yes = 1;
            int cc=0;
            if(x2==niche_w) yes =2, cc = shelves[i].x2-shelves[i].x1;
            else cc = cut_shelf_left(shelves[i],x2);
            if(yes<this_peg) this_peg =yes, this_cut =cc;
            else if(yes==this_peg) this_cut = min(cc,this_cut);
        }
        //  printf("peg %d\n",pegs);
        
        if(yes) {
            pegs+=this_peg;
            if(this_cut!=INT_MAX)
                shorten += this_cut;
        }
        else{
            this_cut = INT_MAX;
            if(shelves[i].px1<=x1 && shelves[i].px2<=x1){
                move(shelves[i],x1-shelves[i].x2);
                this_cut = min(this_cut,l_cut);
                
            }
            if(shelves[i].px2>=x2 && shelves[i].px1>=x2) {
                move(shelves[i],x2-shelves[i].x1);
                this_cut = min(this_cut,l_cut);
            }
            if(this_cut!=INT_MAX)
                shorten+=this_cut;
        }
        //printf("shorten %d\n",shorten);
        
    }
    //printf("result %d %d\n-----------\n",pegs,shorten);
    if(pegs<pegs_removed) pegs_removed =pegs, cut = shorten;
    else if(pegs == pegs_removed) cut = min(cut,shorten);
}
void place_tome(int i){
    if(shelves[i].x2-shelves[i].x1<tome_w || niche_h-shelves[i].y<tome_h) return;
    int l = shelves[i].x2-shelves[i].x1;
    //(y,y + tome_h) x1, x2  
    int x1=max(0,max(shelves[i].px1-l/2,shelves[i].px2-l));
    int x2=min(niche_w-tome_w,min(shelves[i].px2+l/2-tome_w,shelves[i].px1+l-tome_w));
    for(int x=x1;x<=x2;x++){
        clear_rectangle(x,x+tome_w,shelves[i].y,shelves[i].y+tome_h,0);
    }
    x1 = max(0,shelves[i].px1-l);
    x2 = min(niche_w-tome_w,shelves[i].px2+l-tome_w);
    for(int x=x1;x<=x2;x++){
        
        clear_rectangle(x,x+tome_w,shelves[i].y,shelves[i].y+tome_h,1);
    }
    
    x1 = max(0,shelves[i].px2-l);
    x2 = min(niche_w-tome_w,shelves[i].px2+l-tome_w);
    for(int x=x1;x<=x2;x++){
        clear_rectangle(x,x+tome_w,shelves[i].y,shelves[i].y+tome_h,1);
    }
}

int main()
{
    
    int y,x,l,x1,x2;
    scanf("%d%d%d%d",&niche_w,&niche_h,&tome_w,&tome_h);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d%d",&y,&x,&l,&x1,&x2);
        shelves[i].y = y;
        shelves[i].x1 = x;
        shelves[i].x2 = x+l;
        shelves[i].px1 = x1+x;
        shelves[i].px2 = x2+x;
    }
    
    pegs_removed = INT_MAX, cut = INT_MAX;
    for(int i=0;i<n;i++)
        place_tome(i);
    printf("%d %d\n",pegs_removed,cut);
    return 0;
}
