#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
#include <math.h>
#include <queue>
using namespace std;
typedef pair<int,int> PII;
PII degree[20];
int M[20][20];
int n;
bool check()
{
    for(int k=0;k<n;k++){
        sort(degree,degree+n);
        int d = degree[n-1].first;
        int id = degree[n-1].second;
        for(int i=n-2;i>=0;i--)
            if(degree[i].first && d) {
                degree[i].first--;
                d--;
                M[id][degree[i].second] = M[degree[i].second][id] = 1;
                
            }
        degree[n-1].first = 0;
        if(d>0) return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int q=0;q<t;q++){
        scanf("%d",&n);
        memset(M,0,sizeof(M));
        for(int i=0;i<n;i++){
            scanf("%d",&degree[i].first),degree[i].second = i;
        }
        
        if(q) printf("\n");
        if(check()){
            printf("YES\n");
            for(int i=0;i<n;i++){
                printf("%d",M[i][0]);
                for(int j=1;j<n;j++)
                    printf(" %d",M[i][j]);
                printf("\n");
            }
        }else printf("NO\n");
    }
    return 0;
}
