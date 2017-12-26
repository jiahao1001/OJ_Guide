#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;
int n,L;
int len[100000];
int re[100000];
inline bool check(int cnt){
    if(2*cnt<n) return false;
    for(int i=0;i<cnt;i++)
        re[i] = L-len[n-1-i];
    int i=0,j=0;
    while(i<cnt && j<n-cnt){
        while(i<cnt && len[j]>re[i]) i++;
        if(i==cnt) return false;
        i++,j++;
    }
    //cout<<cnt<<" ok"<<endl;
    return  j==n-cnt;
}
int main(){
    scanf("%d%d",&n,&L);
    for(int i=0;i<n;i++)
        scanf("%d",len+i);
    sort(len,len+n);
    int l=0,r = n;
    int mid;
    while(l+1<r){
        mid = (l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%d\n",r);
}
