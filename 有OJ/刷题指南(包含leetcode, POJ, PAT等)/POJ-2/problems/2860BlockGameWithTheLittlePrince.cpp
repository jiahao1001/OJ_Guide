
#include <iostream>
#include <string.h>
#include <utility>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int main(){
    int N,M,K,h;
    vector<int> x,y;
    cin>>N>>M>>K;
    for(int i=0;i<K;i++){
        cin>>h;
        x.push_back(h);
    }
    for(int i=0;i<K;i++){
        cin>>h;
        y.push_back(h);
    }
    int cnt = 0;
    for(int i=0;i<K;i++){
        if(x[i]>y[i]) cnt+=x[i]-y[i];
    }
    cout<<cnt<<endl;
    
    return 0;
}
