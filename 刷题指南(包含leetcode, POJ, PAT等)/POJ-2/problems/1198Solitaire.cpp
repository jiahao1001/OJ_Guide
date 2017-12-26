#include<iostream>
#include<stdio.h>
#include<utility>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
PII start[4];
PII end1[4];
inline int encode(PII *p){
    int h = 0;
    for(int i=0;i<4;i++){
        h = h*64+p[i].first*8+p[i].second;
    }
    return h;
}
inline void decode(int h,PII *p){
    for(int i=3;i>=0;i--){
        int x = h%64;
        p[i].first = x/8, p[i].second = x%8;
        h/=64;
    }
}
set<int> v1,v2;
inline int has(int x,int y,PII *p){
    for(int i=0;i<4;i++)
        if(p[i].first==x && p[i].second == y) return 1;
    return 0;
}
int main()
{
    int x,y;
    for(int i=0;i<4;i++){
        scanf("%d%d",&x,&y);
        x--,y--;
        start[i].first = x, start[i].second = y;
    }
    sort(start,start+4);
    for(int i=0;i<4;i++){
        scanf("%d%d",&x,&y);
        x--,y--;
        end1[i].first = x, end1[i].second = y;
    }
    sort(end1,end1+4);
    int s = encode(start);
    int e = encode(end1);
    if(s==e) {
        printf("YES\n");
        return 0;
    }
    PII p[4];
    PII np[4];
    queue<int> q1,q2;
    v1.insert(s), v2.insert(e);
    q1.push(s),q2.push(e);
    bool ok = false;
    for(int d=1;d<=4;d++){
        //q1 then q2
        int cnt = q1.size();
        for(int m=0;m<cnt;m++){
            int hd = q1.front();
            q1.pop();
            //expand
            decode(hd,p);
            //go to empty neighbor
            for(int i=0;i<4;i++){
                for(int dx=-1;dx<=1;dx++)
                    for(int dy=-1;dy<=1;dy++)
                        if((dx==0)^(dy==0)){
                            x = p[i].first+dx, y = p[i].second+dy;
                            if(x<0 || x>= 8 || y<0 || y>=8) continue;
                            if(!has(x,y,p)){
                                for(int k=0;k<4;k++)
                                    np[k] = p[k];
                                np[i] = make_pair(x,y);
                                sort(np,np+4);
                                int nh = encode(np);
                                if(v2.count(nh)){
                                    ok = true;
                                    goto A;
                                }
                                v1.insert(nh);
                                q1.push(nh);
                            }else{
                                x = p[i].first+2*dx, y = p[i].second+2*dy;
                                if(x<0 || x>= 8 || y<0 || y>=8) continue;
                                if(has(x,y,p)) continue;
                                for(int k=0;k<4;k++)
                                    np[k] = p[k];
                                np[i] = make_pair(x,y);
                                sort(np,np+4);
                                int nh = encode(np);
                                if(v2.count(nh)){
                                    ok = true;
                                    goto A;
                                }
                                v1.insert(nh);
                                q1.push(nh);
                            }
                        }
            }
        }
        
        cnt = q2.size();
        for(int m=0;m<cnt;m++){
            int hd = q2.front();
            q2.pop();
            decode(hd,p);
            //expand
            for(int i=0;i<4;i++){
                for(int dx=-1;dx<=1;dx++)
                    for(int dy=-1;dy<=1;dy++)
                        if((dx==0)^(dy==0)){
                            x = p[i].first+dx, y = p[i].second+dy;
                            if(x<0 || x>= 8 || y<0 || y>=8) continue;
                            if(!has(x,y,p)){
                                for(int k=0;k<4;k++)
                                    np[k] = p[k];
                                np[i] = make_pair(x,y);
                                sort(np,np+4);
                                int nh = encode(np);
                                if(v1.count(nh)){
                                    ok = true;
                                    goto A;
                                }
                                v2.insert(nh);
                                q2.push(nh);
                            }else{
                                x = p[i].first+2*dx, y = p[i].second+2*dy;
                                if(x<0 || x>= 8 || y<0 || y>=8) continue;
                                if(has(x,y,p)) continue;
                                for(int k=0;k<4;k++)
                                    np[k] = p[k];
                                np[i] = make_pair(x,y);
                                sort(np,np+4);
                                int nh = encode(np);
                                if(v1.count(nh)){
                                    ok = true;
                                    goto A;
                                }
                                v2.insert(nh);
                                q2.push(nh);
                            }
                        }
            }
        }
        
    }
A:
    if(ok) printf("YES\n");
    else printf("NO\n");
    return 0;
}   
