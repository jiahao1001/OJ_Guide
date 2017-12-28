#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
#include<set>
#include<string>
#include<limits.h>
#include<algorithm>
#include<float.h>
using namespace std;
int sign(long long x){
    if(x>0) return 1;
    else if(x<0) return -1;
    else return 0;
}
long long abs1(long long x){
   if(x<0) return -x;
   return x;
}
int main(){
    int n;
    long long a;
    while(scanf("%d",&n),n){
        long long work = 0;
        deque<pair<int,long long> > Q;
        for(int i=0;i<n;i++){
            scanf("%lld",&a);
            if(Q.empty()) Q.push_back(make_pair(i,a));
            else{
                if(sign(a)*sign(Q.front().second)==1) Q.push_back(make_pair(i,a));
                else{
                    //begin work
                    while(!Q.empty() && abs1(a)>= abs1(Q.front().second)){
                        work += (i-Q.front().first)*abs1(Q.front().second);
                        a+=Q.front().second;
                        Q.pop_front();
                    }
                    if(abs1(a)!=0){
                        if(Q.empty()) Q.push_back(make_pair(i,a));
                        else work += (i-Q[0].first)*abs1(a), Q[0].second += a;
                    }
                }
            }
        }
        printf("%lld\n",work);
        
    }
    return 0;
}
