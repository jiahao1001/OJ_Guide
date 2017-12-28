#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
typedef pair<int,int> PII;
const int M = 10001;
const int N = 1001;
const int R = 1000;
int n_cnt,m_cnt,r,q;
int t[R],n[R],m[R],s[R];
int b,e,id;
int login[N];// login time for computer n -1 means logged out
inline int get_time(){
    //student id
    //time [b,e)
    //scan through, only care about m[i]==id
    vector<PII> intervals;
    int start,end;
    for(int i=0;i<r;i++){
        if(m[i]!=id) continue;
        if(s[i]) login[n[i]] = t[i];
        else{
            //get a interval
            start = login[n[i]];
            login[n[i]] = -1;
            end = t[i];
            start = max(start,b);
            end = min(end,e);
            if(start<end) intervals.push_back(make_pair(start,end));
        }
    }
    //for(int i=0;i<intervals.size();i++)
    //    printf("%d %d\n",intervals[i].first,intervals[i].second);
    //merge the intervals
    sort(intervals.begin(),intervals.end());
    int total = 0;
    int last_s = -1, last_e = -1;
    for(int i=0;i<intervals.size();i++){
        if(intervals[i].first>last_e){
            total += (last_e-last_s);
            //new interval
            last_s = intervals[i].first;
            last_e = intervals[i].second;
        }else{
            last_e = max(last_e,intervals[i].second);
        }
    }
    total += (last_e-last_s);
    return total;
    
}
int main()
{
    while(scanf("%d%d",&n_cnt,&m_cnt),n_cnt||m_cnt){
        scanf("%d",&r);
        for(int i=0;i<r;i++)
            scanf("%d%d%d%d",t+i,n+i,m+i,s+i);
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            scanf("%d%d%d",&b,&e,&id);
            memset(login,-1,sizeof(login));
            printf("%d\n",get_time());
        }
    }
    return 0;
}
