#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
#include<sstream>
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<assert.h>
#include<numeric>
#include<map>
using namespace std;
int L,N,M;
vector<int> rock;
bool check(int d){
    //remove <=M rock
    int last = 0;
    int cnt = 1;
    int i=1;
    bool take = false;
    while(i<=N){
        while(i<=N && rock[i]-last<d) i++;
        if(i==N) take = true;
        if(i<=N) last = rock[i],cnt++;
        i++;
    }
    cnt++;
    if(take && L-rock[N]<d) cnt--;
    
    return N+2-cnt<=M;
}
int main(){
    scanf("%d%d%d",&L,&N,&M);
    int d;
    for(int i=0;i<N;i++){
        scanf("%d",&d);
        rock.push_back(d);
    }
    rock.push_back(0),rock.push_back(L);
    sort(rock.begin(),rock.end());
    if(M==N) {
        printf("%d\n",L);
        return 0;
    }
    int l = 0, r = L;
    int mid;
    while(l+1<r){
        mid = (l+r)>>1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%d\n",l);
}
