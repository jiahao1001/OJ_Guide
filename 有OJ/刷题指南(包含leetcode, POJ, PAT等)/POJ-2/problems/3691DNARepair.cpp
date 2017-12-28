#include<vector>
#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
#include<assert.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int toI(char c){
    switch(c){
        case 'A':return 0;
        case 'G':return 1;
        case 'C':return 2;
        case 'T':return 3;
    }
    return -1;
}

class AC{
public:
    int cnt;
    int chd[10000][4];
    int fail[10000];
    int words[10000];
    int root;
    int que[10000];
    void init(){
        root = 0;
        cnt = 1;
        memset(chd[0],-1,sizeof(chd[0]));
        words[0] = 0;
    }
    void insert(char *word){
        int len=strlen(word);
        int cur=root;
        for(int i=0;i<len;i++){
            if(chd[cur][toI(word[i])]<0){
                //get a new node
                cnt++;
                //assert(cnt<1000);
                memset(chd[cnt-1],-1,sizeof(chd[cnt-1]));
                chd[cur][toI(word[i])] = cnt-1;
                words[cnt-1] = 0;
                
            }
            cur = chd[cur][toI(word[i])];
        }
        words[cur]=1;
    }
    void build(){
        //phase I 
        for(int i=0;i<4;i++) if(chd[0][i]<0) chd[0][i]=0;
        //phase II bfs
        int s,t,q,r,v;
        s=t=0;
        for(int i=0;i<4;i++) if(q=chd[0][i]){
            fail[q] = 0;
            que[t++] = q;
        }
        while(s<t){
            r = que[s++];
            for(int i=0;i<4;i++){
                if((q=chd[r][i])!=-1){
                    que[t++] = q;
                    v = fail[r];
                    while(chd[v][i]<0) v = fail[v];
                    fail[q] = chd[v][i];
                    words[q] |= words[fail[q]];
                }
            }
        }
    }
   
    
};
char S[1010];
AC ac;
int dp[1010][10000];
int main(){
    int n;
    char word[60];
    int q=1;
    while(scanf("%d",&n),n){
        ac.init();
        for(int i=0;i<n;i++){
            scanf("%s",word);
            ac.insert(word);
        }
        ac.build();
        scanf("%s",S);
        //cout<<S<<endl;
        //cout<<ac.cnt<<endl;
        //for(int i=0;i<ac.cnt;i++)
        //    cout<<ac.words[i]<<endl;
        int m = strlen(S);
        memset(dp,0x3f,sizeof(dp));
        dp[0][0] = 0;
        for(int i=1;i<=m;i++)
            for(int j=0;j<ac.cnt;j++){
                if(ac.words[j]||dp[i-1][j]==INF) continue;
                for(int k=0;k<4;k++){
                    int v = j;
                    while(ac.chd[v][k]<0){
                        v=ac.fail[v];
                    }
                    v = ac.chd[v][k];
                    if(!ac.words[v])
                        dp[i][v] = min(dp[i][v], dp[i-1][j]+(toI(S[i-1])!=k));
                    
                }
            }
       
        int answer = INF;
        for(int j=0;j<ac.cnt;j++) answer = min(answer,dp[m][j]);
        printf("Case %d: ",q++);
        if(answer==INF) printf("-1\n");
        else printf("%d\n",answer);
    }
}
