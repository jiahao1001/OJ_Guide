#include<iostream>
#include<stdio.h>
#include<set>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> PI;
const int N = 50000;
int n,m;
int d[N],s[N];
PI p[N];
int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<n;i++) scanf("%d",d+i);
        for(int i=0;i<n;i++) scanf("%d",s+i);
        priority_queue<PI> pq;
        for(int i=0;i<n;i++)
            p[i] = make_pair(s[i],d[i]);
        sort(p,p+n);
        set<int,greater<int> > S;
        for(int i=0;i<=m;i++) S.insert(i);
        int demage = 0;
        for(int i=n-1;i>=0;i--){
            PI &h = p[i];
            set<int,greater<int> >::iterator it = S.lower_bound(h.second);
            if(*it ==0) demage += h.first;
            else S.erase(it);
        }
        printf("%d\n",demage);
    }
    return 0;
}
