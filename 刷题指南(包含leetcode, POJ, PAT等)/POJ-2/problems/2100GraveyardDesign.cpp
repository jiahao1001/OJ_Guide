#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdio.h>
#include <queue>
using namespace std;
long long n;
typedef pair<int,int>  PI;
vector<PI> v;
int main(){
    scanf("%lld",&n);
    long long sum = 1;
    long long h = 1, r = 2;
    if(n==1){
        printf("1\n1 1\n");
        return 0;
    }
    while(r*r<=n){
        while(sum<n) {
            sum+=r*r,r++;
        }
        while(sum>n) sum-=h*h, h++;
        if(sum==n){
            v.push_back(make_pair(r-h, h));
            sum -= h*h;
            h++;
        }
    }
    sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(int i=v.size()-1;i>=0;i--){
        printf("%d",v[i].first);
        for(int x=0;x<v[i].first;x++)
            printf(" %d",v[i].second+x);
        printf("\n");
    }
    return 0;
}
