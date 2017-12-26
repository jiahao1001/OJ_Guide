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
int cnt[101];
int n,q;
int main(){
    int m,d;
    while(scanf("%d%d",&n,&q),n||q){
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            for(int j=0;j<m;j++){
                scanf("%d",&d);
                cnt[d]++;
            }
        }
        int most = -1;
        int day = 0;
        for(int i=1;i<=100;i++){
            if(cnt[i]>=q && cnt[i]>most) most=cnt[i],day=i;
        }
        printf("%d\n",day);
    }
    
    return 0;
}
