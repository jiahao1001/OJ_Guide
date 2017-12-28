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
#include<set>
#include<numeric>
#include<map>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 1001;
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
int visited[MAXN][MAXN];
int answer[1001];
int cnt = 0;
void add_point(int i,int j){
    int g = gcd(i,j);
    if(!visited[i/g][j/g]){
        cnt++;
        visited[i/g][j/g] = 1;
    }
}
int main() {
    for (int k = 1; k <= 1000; k++) {
        for(int i=0;i<=k;i++) add_point(i,k);
        for(int i=0;i<k;i++) add_point(k,i);
        answer[k] = cnt;
    }
    int C, N;
    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        scanf("%d", &N);
        printf("%d %d %d\n", i + 1, N, answer[N]);
    }
    return 0;
}
