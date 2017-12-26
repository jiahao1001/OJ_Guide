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
const int MAXN = 30000;
int N,L;
int len[MAXN];
int main()
{
    scanf("%d%d",&N,&L);
    for(int i=0;i<N;i++) scanf("%d",len+i);
    int year = 0;
    while(true){
        for(int i=0;i<N;i++)
            if(len[i]%L==0) len[i]=0;
        
        bool has = false;
        for(int i=0;i<N;i++) {
            if(len[i]) len[i]++, has=true;
        }
        if(!has) break;
        year++;
    }
    printf("%d\n",year);
}
