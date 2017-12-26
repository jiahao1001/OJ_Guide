#include<iostream>
#include<stdio.h>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
const int MOVE = 10;
const int ROTATE = 5;
pii loc[2510];
int car[50][50];
int p[50];
int h,l;
int cnt;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        cnt = 0;
        scanf("%d%d",&h,&l);
        for(int i=0;i<h;i++)
            for(int j=0;j<l;j++){
                scanf("%d",&car[i][j]),cnt = max(cnt,car[i][j]);
                if(car[i][j]!=-1) loc[car[i][j]].first = i, loc[car[i][j]].second = j;
            }
        for(int i=0;i<h;i++) p[i] = 0;
        int tot = 0;
        for(int c=1;c<=cnt;c++){
            int i = loc[c].first;
            int j = loc[c].second;
            tot += 2*i*MOVE;
            tot += ROTATE*min((p[i]-j+l)%l,(j-p[i]+l)%l);
            p[i] = j;
        }
        printf("%d\n",tot);
    }
    return 0;
}
