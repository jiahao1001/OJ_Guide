
#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    int T,N;
    scanf("%d%d",&T,&N);
    vector<int> left;
    vector<int> right;
    int x;
    int cnt = 0;
    for(int i=0;i<N;i++){
        scanf("%d",&x);
        if(x==0) cnt++;
        else if(x<0) left.push_back(-x);
        else right.push_back(x);
    }
    sort(left.begin(),left.end());
    sort(right.begin(),right.end());
    int cur_x = 0;
    int t = 0;
    int i=0,j=0;
    int len;
    while(t<=T && (i<left.size() || j<right.size())){
        if(i<left.size() && j<right.size()){
            if( left[i]<right[j]){
                x = left[i++];
                len = abs(cur_x+x);
                if(t+len<=T) cnt++;
                t+=len;
                cur_x = -x;
            }else{
                x = right[j++];
                len = abs(cur_x-x);
                if(t+len<=T) cnt++;
                t+=len;
                cur_x = x;
            }
        }
        else{
            if(i<left.size()){
                x = left[i++];
                len = abs(cur_x+x);
                if(t+len<=T) cnt++;
                t+=len;
                cur_x = -x;
            }
            if(j<right.size()){
                x = right[j++];
                len = abs(cur_x-x);
                if(t+len<=T) cnt++;
                t+=len;
                cur_x = x;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
