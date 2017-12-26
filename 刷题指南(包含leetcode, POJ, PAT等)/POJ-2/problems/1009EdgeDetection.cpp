#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
#include<vector>
#include<utility>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef pair<int,int> PII;
int w;
vector<PII> V[3];
vector<PII> *U;
vector<PII> *M;
vector<PII> *D;
vector<PII> RLE;
int u,m,d;
int cur;
int lp,lc;
void fillrow(){
    (*D).clear();
    if(cur==RLE.size()){
        cur++;
        for(int i=0;i<(*M).size();i++)
            (*D).push_back((*M)[i]);
        return;
    }
    int cnt = 0;
    while(cur<RLE.size() &&cnt+RLE[cur].second<=w) {
        cnt+=RLE[cur].second;
        (*D).push_back(make_pair(cnt,RLE[cur].first));
        cur++;
    }
    if(cnt<w){
        int diff = w-cnt;
        (*D).push_back(make_pair(w,RLE[cur].first));
        RLE[cur].second -= diff;
    }
}
void init(){
    for(int i=0;i<3;i++)
        V[i].clear();
    u=0,m=1,d=2;
    U = &V[0];
    M = &V[1];
    D = &V[2];
    lp = lc = -1;
    RLE.clear();
    int p,c;
    while(scanf("%d%d",&p,&c),c){
        RLE.push_back(make_pair(p,c));
    }
    cur = 0;
    (*M).clear();
    int cnt = 0;
    while(cur<RLE.size() && cnt+RLE[cur].second<=w) {
        cnt+=RLE[cur].second;
        (*M).push_back(make_pair(cnt,RLE[cur].first));
        cur++;
    }
    if(cnt<w){
        int diff = w-cnt;
        (*M).push_back(make_pair(w,RLE[cur].first));
        RLE[cur].second -= diff;
    }
    
    fillrow();
    for(int i=0;i<(*M).size();i++)
        (*U).push_back((*M)[i]);
    
}


void advance(){
    u = (u+1)%3;
    m = (m+1)%3;
    d = (d+1)%3;
    U = &V[u],M=&V[m],D=&V[d];
    fillrow();
}
void merge(int p,int c){
    //cout<<"merge "<<p<<" "<<c<<endl;
    if(c<=0) return;
    if(p!=lp){
        if(lp+lc!=-2)printf("%d %d\n",lp,lc);
        lp=p,lc=c;
        return;
    }
    lc+=c;
}
int getP(vector<PII> *VP,int i){
    return upper_bound(VP->begin(),VP->end(),make_pair(i,1000))->second;
}
int getPixel(int i){
    int p = 0;
    int center = getP(M,i);
    if(i-1>=0){
        p=max(p,abs(getP(U,i-1)-center));
        p=max(p,abs(getP(M,i-1)-center));
        p=max(p,abs(getP(D,i-1)-center));
    }
    if(i+1<w){
        p=max(p,abs(getP(U,i+1)-center));
        p=max(p,abs(getP(M,i+1)-center));
        p=max(p,abs(getP(D,i+1)-center));
    }
    p=max(p,abs(getP(U,i)-center));
    p=max(p,abs(getP(D,i)-center));
    
    //cout<<"pixel"<<i<<" "<<p<<endl;
    return p;
    
}
void calc(){
    vector<int> v;
    for(int i=0;i<(*U).size();i++)
        v.push_back((*U)[i].first);
    for(int i=0;i<(*M).size();i++)
        v.push_back((*M)[i].first);
    for(int i=0;i<(*D).size();i++)
        v.push_back((*D)[i].first);
    sort(v.begin(),v.end());
    std::vector<int>::iterator it;
    it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(),it));
    //for(int i=0;i<v.size();i++)
    //  cout<<v[i]<<endl;
    int last = 0;
    for(int i=0;i<v.size();i++){
        int u = v[i];
        //last --> u-2
        int p = getPixel(last);
        merge(p,u-2-last+1);
        if(u-1>=last){
            p = getPixel(u-1);
            merge(p,1);
        }
        //u-1
        //u
        if(u<w){
            p=getPixel(u);
            merge(p,1);
        }
        last = u+1;
    }
    
}

int main(){
    while(scanf("%d",&w),w){
        printf("%d\n",w);
        init();
        //printf("----------------\n");
        calc();
        if(cur<RLE.size() && RLE[cur].first==(*M)[0].second && (*M)[0].first==w){
            int n = RLE[cur].second;
            int zeroline = (n-1)/w;
            merge(0,zeroline*w);
            RLE[cur].second-=zeroline*w;
        }
        while(cur<=RLE.size()){
            advance();
            //printf("----------------\n");
            calc();
            if(cur<RLE.size() && RLE[cur].first==(*M)[0].second && (*M)[0].first==w){
                int n = RLE[cur].second;
                int zeroline = (n-1)/w;
                merge(0,zeroline*w);
                RLE[cur].second-=zeroline*w;
            }
            
            
        }
        printf("%d %d\n",lp,lc);
        printf("0 0\n");
    }
    printf("0\n");
    return 0;
}
