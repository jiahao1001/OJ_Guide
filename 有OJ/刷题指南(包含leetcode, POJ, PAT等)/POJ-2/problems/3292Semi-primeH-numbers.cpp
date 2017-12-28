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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctype.h>
#include <climits>
using namespace std;
const long long N = 1000010;
int cnt[N];
int is_prime[N];
long long prime[N];
int n;
int main()
{
    int h;
    
    for(int i=0;i<N;i++) is_prime[i] = 0;
    is_prime[1] = 0;
    for(int i=1;(4*i+1)*(4*i+1)<N;i++){
        if(is_prime[4*i+1]==0)
            for(int j=i;(4*i+1)*(4*j+1)<N;j++)
                is_prime[(4*i+1)*(4*j+1)] = is_prime[4*i+1]+is_prime[4*j+1]+1;
    }  
    for(int i=25;i<N;i++) is_prime[i]=(is_prime[i]==1)+is_prime[i-1];
    while(scanf("%d",&h),h){
        printf("%d %d\n",h,is_prime[h]);
    }
}
