#include <iostream>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <stdio.h>
using namespace std;
vector<double> X;
vector<double> Y;//unique

struct Seg{
    double y1,y2;
    double x;
    int cover;
    Seg(double _x,double _y1,double _y2,int _cover):x(_x),y1(_y1),y2(_y2),cover(_cover)
    {}
    Seg(){}
} segs[200];
bool operator<(const Seg& s1,const Seg& s2){
    return s1.x<s2.x;
}
struct Node{
    int l,r;
    int cover;
    double len;
} tree[800];

void build_tree(int rt,int l,int r){
    tree[rt].l = l, tree[rt].r = r;
    tree[rt].cover = 0;
    tree[rt].len = 0;
    if(r-l==1) return;
    int mid = (l+r)>>1;
    build_tree(2*rt+1,l,mid);
    build_tree(2*rt+2,mid,r);
}
void push_up(int rt){
    if(tree[rt].cover){
        tree[rt].len = Y[tree[rt].r]-Y[tree[rt].l];
    }else if(tree[rt].l+1==tree[rt].r) tree[rt].len=0;
    else tree[rt].len = tree[2*rt+1].len + tree[2*rt+2].len;
}
void push_down(int rt){
    if(tree[rt].cover<0)
        cout<<tree[rt].cover<<endl;
    assert(tree[rt].cover>=0);
    
    if(tree[rt].cover){
        tree[2*rt+1].cover += tree[rt].cover;
        tree[2*rt+2].cover += tree[rt].cover;
        push_up(2*rt+1);
        push_up(2*rt+2);
        tree[rt].cover = 0;
    }
}
void update(int rt,int l,int r,int cover){
    if(l<=tree[rt].l && tree[rt].r<=r && tree[rt].cover + cover>=0){
        tree[rt].cover += cover;
        push_up(rt);
        return;
    }
    push_down(rt);
    int mid = (tree[rt].l + tree[rt].r)>>1;
    if(l<mid) update(2*rt+1,l,r,cover);
    if(r>mid) update(2*rt+2,l,r,cover);
    push_up(rt);
    
}

int main(){
    int q = 1;
    int n, cnt;
    double area;
    double x1,y1,x2,y2;
    while(scanf("%d",&n),n){
        area = 0;
        cnt = 0;
        X.clear();
        Y.clear();
        for(int i=0;i<n;i++){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            X.push_back(x1);
            X.push_back(x2);
            Y.push_back(y1);
            Y.push_back(y2);
            segs[2*i] = Seg(x1,y1,y2,1);
            segs[2*i+1] = Seg(x2,y1,y2,-1);
        }
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        sort(segs,segs+2*n);
        cnt = unique(Y.begin(),Y.end()) - Y.begin();
        build_tree(0,0,cnt-1);
        for(int i=0;i<2*n-1;i++){
            int l = lower_bound(Y.begin(),Y.begin()+cnt,segs[i].y1) - Y.begin();
            int r = lower_bound(Y.begin(),Y.begin()+cnt,segs[i].y2) - Y.begin();
            update(0,l,r,segs[i].cover);
            area += (segs[i+1].x - segs[i].x)*tree[0].len;
        }
        
        printf("Test case #%d\n",q++);
        printf("Total explored area: %.2f\n\n",area);
    }
    return 0;
}
