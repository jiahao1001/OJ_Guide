#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctime>

using namespace std;
int n,d;
int cnt[100];
inline bool check(){
    for(int i=0;i<n;i++)
        if(cnt[i]==d) return true;
    return false;
}
int main()
{
    while(scanf("%d%d",&n,&d),n||d)
    {
        int a;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<d;i++)
            for(int j=0;j<n;j++){
                scanf("%d",&a);
                cnt[j]+=a;
            }
        if(check()) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
