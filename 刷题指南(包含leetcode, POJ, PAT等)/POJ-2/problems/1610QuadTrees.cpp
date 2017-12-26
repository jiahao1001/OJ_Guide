#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 530;
typedef pair<pair<int,int>,int> P;
#define make_P(i,j,d) make_pair(make_pair(i,j),d)
int p[N][N];
int s[N][N];
int k,n;
int get_sum(int i1,int j1,int i2,int j2){
    return s[i2][j2]-s[i1-1][j2]-s[i2][j1-1]+s[i1-1][j1-1];
}
int main()
{
    scanf("%d",&k);
    while(k--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) scanf("%d",&p[i][j]);
        memset(s,0,sizeof s);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) s[i][j] = p[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        P init = make_pair(make_pair(1,1),n);
        vector<int> binary;
        queue<P> Q;
        Q.push(init);
        while(!Q.empty()){
            P head = Q.front();
            int i = head.first.first;
            int j = head.first.second;
            int d = head.second;
            Q.pop();
            int sum = get_sum(i,j,i+d-1,j+d-1);
            if(sum==0){
                //printf("(0,0)");
                binary.push_back(0);
                binary.push_back(0);
            }else if(sum==d*d){
                //printf("(0,1)");
                binary.push_back(0);
                binary.push_back(1);
            }else{
                //printf("(1)");
                binary.push_back(1);
                Q.push(make_P(i,j,d/2));
                Q.push(make_P(i,j+d/2,d/2));
                Q.push(make_P(i+d/2,j,d/2));
                Q.push(make_P(i+d/2,j+d/2,d/2));
            }
        }
        vector<int> hex;
        for(int i = binary.size()-1;i>=0;){
            int cnt = 0;
            int num = 0;
            int b=1;
            while(cnt<4 && i>=0) num += binary[i]*b,b*=2,i--,cnt++;
            hex.push_back(num);
            //cout<<num<<endl;
        }
        for(int i=hex.size()-1;i>=0;i--){
            if(hex[i]<10) printf("%d",hex[i]);
            else printf("%c",hex[i]-10+'A');
        }
        printf("\n");
        
    }
    return 0;
}
