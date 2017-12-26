#include<queue>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
#include<string>
using namespace std;
string team[40];
int round[40];
int n,m;
char buf[100][205];
int main()
{
    int cs = 1;
    while(cin>>n){
        if(n==-1) break;
        for(int i=0;i<n;i++)
            cin>>team[i];
        memset(round,-1,sizeof round);
        round[n-1] = 0;
        m = 0;
        queue<int> q;
        q.push(n-1);
        while(!q.empty()){
            int h = q.front();
            q.pop();
            int x = ((h>>1)<<1)-2;
            for(;x>=0;x-=2){
                if(team[x]==team[h]||team[x+1]==team[h]) break;
            }
            if(x>=0){
                round[x] = round[x+1] = round[h]+1;
                m = max(m,round[x]);
                q.push(x), q.push(x+1);
            }
        }
        vector<vector<string> > g(m+1,vector<string>());
        q.push(n-1);
        g[0].push_back(team[n-1]);
        while(!q.empty()){
            int h = q.front();
            q.pop();
            int x=((h>>1)<<1)-2;
            int d = round[h];
            for(;x>=0;x-=2){
                if(team[x]==team[h]||team[x+1]==team[h]) break;
            }
            if(x>=0){
                q.push(x),q.push(x+1);
                g[d+1].push_back(team[x]);
                g[d+1].push_back(team[x+1]);
            }else if(round[h]<m){
                g[d+1].push_back("");
                g[d+1].push_back("");
            }
        }
        printf("Tournament %d\n",cs++);
        memset(buf,' ',sizeof buf);
        int line = 2*(g[m].size()-1)+1;
        //cout<<line<<endl;
        int cur = 0;
        for(int i=m;i>=0;i--){
            int r = m-i;
            //start from line 2^r
            //space 2^(r+1)
            //2^r slash
            int wid = 0;
            for(int j=0;j<g[i].size();j++)
                wid = max(wid,(int)g[i][j].size()+2);
            int a = 1<<r;
            int b = a<<1;
            for(int j=0,l=a;j<g[i].size();j++,l+=b){
                if(!g[i][j].size()) continue;
                int k = cur;
                buf[l][k++] = '_';
                for(int x=0;x<g[i][j].size();x++)
                    buf[l][k++] = g[i][j][x];
                for(int x=0;x<wid-1-g[i][j].size();x++)
                    buf[l][k++] = '_';
                if(g[i].size()==1) continue;
                if(j%2){
                    for(int x=l,y=cur+wid,cnt=0;cnt<a;cnt++,x--,y++)
                        buf[x][y]='/';
                    // up slash
                }else{
                    for(int x=l+1,y=cur+wid,cnt=0;cnt<a;cnt++,x++,y++)
                        buf[x][y]='\\';
                }
                
            }
            cur+=wid+a;
        }
        for(int i=1;i<=line;i++){
            int j;
            for(j=200;j>=0;j--){
                if(buf[i][j]!=' ') break;
            }
            buf[i][j+1] = 0;
            if(j==-1)continue;
            printf("%s\n",buf[i]);
        }
    }
    return 0;
}
