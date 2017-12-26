#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 20000;
int n;
struct Doll{
    int h,w;
} dolls[N];
bool operator<(const Doll& d1,const Doll& d2){
    if(d1.h==d2.h) return d1.w<d2.w;
    else return d1.h>d2.h;
}
int main()
{
    int h,w,k;
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&w,&h);
            dolls[i].h = h, dolls[i].w = w;
        }
        sort(dolls,dolls+n);
        vector<int> v;//the w
        for(int i=0;i<n;i++){
            int j = upper_bound(v.begin(),v.end(),dolls[i].w)-v.begin();
            if(j==v.size()) v.push_back(dolls[i].w);
            else v[j] = dolls[i].w;
        }
        printf("%d\n",v.size());
        
    }
    return 0;
}
