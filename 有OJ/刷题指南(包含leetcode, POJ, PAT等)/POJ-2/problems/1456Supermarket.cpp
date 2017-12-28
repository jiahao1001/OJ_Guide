
#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;
const int N = 10010;
int n;
vector<int> profit[N];
int main(){
    while(scanf("%d",&n)!=EOF){
        int max_d = 0;
        int p,d;
        for(int i=0;i<N;i++)
            profit[i].clear();
        for(int i=0;i<n;i++){
            scanf("%d%d",&p,&d);
            profit[d].push_back(p);
            max_d = max(max_d,d);
        }
        priority_queue<int> pq;
        int best = 0;
        for(d=max_d;d>=1;d--){
            for(int i=0;i<profit[d].size();i++){
                pq.push(profit[d][i]);
            }
            if(pq.empty()) continue;
            best += pq.top();
            pq.pop();
        }
        printf("%d\n",best);
    }
}
