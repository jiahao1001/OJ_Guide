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
int n;
int killed[150];
int main()
{
    while(scanf("%d",&n),n){
        int m =1;
        int i,cur,cnt;
        while(true){
            //cout<<"M "<<m<<endl;
            memset(killed,0,sizeof(killed));
            cur = 0;
            cnt = 0;
            killed[0] = 1;
            for(i=2;i<=n;i++){
                cnt = 0;
                while(true) {
                    if(!killed[cur]) cnt++;
                    //if(cnt==m) break;
                    if(cnt==((m%(n-i+1))?(m%(n-i+1)):(n-i+1))) break;
                    cur = (cur+1)%n;
                    
                    //printf("(%d,%d)\n",cur,cnt);
                }
                //cout<<"kill "<<cur<<endl;
                killed[cur]=1;
                if(cur==1) break;
            }
            if(i==n) break;
            m++;
        }
        printf("%d\n",m);
    }
    return 0;
}
