#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 100001;
const int K = 30;
const int M = 99983;
int n,k;
int A[N];
int s[N][K];
int a[N][K];
int dict[1000000];
int ans;
int hash1(int *v,int k){
    unsigned int h = 0;
    for(int i=0;i<k;i++){
        h = (h<<4)+v[i];
        unsigned int g = h&(0xF0000000);
        if(g) h^=(g>>24);
        h &=~g;
    }
    return h%M;
}
int main()
{
    scanf("%d%d",&n,&k);
    memset(dict,-1,sizeof(dict));
    for(int i=1;i<=n;i++) scanf("%d",A+i);
    for(int i=1;i<=n;i++)
        for(int j=0;j<k;j++) s[i][j] = A[i]%2,A[i]/=2;
    for(int i=1;i<=n;i++)
        for(int j=0;j<k;j++){
            s[i][j] += s[i-1][j];
        }
    for(int i=0;i<=n;i++)
        for(int j=0;j<k;j++) a[i][j] = s[i][j]-s[i][0];
    dict[hash1(a[0],k)] = 0;
    ans = 0;
    //cout<<"good"<<endl;
    for(int i=1;i<=n;i++){
        int p = hash1(a[i],k);
        int id;
        while((id=dict[p])!=-1){
            int j;
            for(j=1;j<k;j++)
                if(a[i][j]!=a[id][j]) break;
            if(j==k){
                ans = max(ans,i-id);
                break;
            }
            p++;
            //      cout<<"GGG"<<endl;
        }
        if(dict[p]==-1) dict[p]=i;
        
    }
    printf("%d\n",ans);
    
    
    return 0;
}
