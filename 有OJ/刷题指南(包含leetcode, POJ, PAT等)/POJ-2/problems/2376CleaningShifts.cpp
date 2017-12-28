#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
typedef pair<int,int> PII;
const int MAXN = 25000;
int N,T;
PII intervals[MAXN];
int main()
{
    scanf("%d%d",&N,&T);
    for(int i=0;i<N;i++){
        scanf("%d%d",&intervals[i].first, &intervals[i].second);
    }
    sort(intervals,intervals+N);
    int hire = 0;
    int last = 0;
    int far = -1;
    for(int i=0;i<N;i++){
        if(intervals[i].first<=last+1) far=max(far,intervals[i].second);
        else{
            i--;
            if(far==-1){
                printf("-1\n");
                return 0;
            }else hire++, last = far,far=-1;
        }
        if(far>=T) break;
    }
    if(far<T) printf("-1\n");
    else printf("%d\n",hire+1);
    
    return 0;
}
