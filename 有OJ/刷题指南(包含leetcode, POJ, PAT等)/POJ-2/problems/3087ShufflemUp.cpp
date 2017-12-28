#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<string>
#include<limits.h>
#include<queue>
using namespace std;
string target;
string start;
int C;
inline string shuffle(const string &s1,const string &s2){
    string s = "";
    for(int i=0;i<C;i++)
        s+=string(1,s2[i])+string(1,s1[i]);
    return s;
}
inline int bfs()
{
    map<string,int> dist;
    dist[start] = 1;
    queue<string> Q;
    Q.push(start);
    while(!Q.empty()){
        string head = Q.front();
        Q.pop();
        int d =dist[head];
        if(head==target) return d;
        string s = shuffle(head.substr(0,C),head.substr(C,C));
        if(dist.count(s)) continue;
        dist[s] = d+1;
        Q.push(s);
    }
    return -1;
}
int main()
{
    int t;
    string s1,s2;
    scanf("%d",&t);
    int q=1;
    while(t--){
        scanf("%d",&C);
        cin>>s1>>s2;
        cin>>target;
        start = shuffle(s1,s2);
        printf("%d %d\n",q++,bfs());
    }
    return 0;
}
