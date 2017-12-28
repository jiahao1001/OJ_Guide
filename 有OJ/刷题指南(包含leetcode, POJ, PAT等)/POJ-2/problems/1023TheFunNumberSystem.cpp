#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string.h>
#include<stack>
#include<limits.h>
using namespace std;
int main(){
    int t,k;
    long long n;
    char p[70];
    int repr[70],cnt;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        scanf("%s",p);
        scanf("%lld",&n);
        if(n==1LL<<63){
            n = -1;
            k-=63;
        }
        //printf("%lld\n",1ll<<63);
        if(n<0) {
            n = -n;
            for(int i=0;i<k;i++) if(p[i]=='p') p[i]='n';
            else p[i]='p';
        }
        cnt = 0;
        k--;
        bool failed = false;
        while(true){
            if(k<0) {
                break;
            }
            char c = p[k--];
            int d = n%2;
            n/=2;
            if(c=='p') repr[cnt++] = d;
            else{
                if(d==1) repr[cnt++] = d, n+=1;
                else repr[cnt++] = d;
            }
            //printf("(%d,%d)\n",d,n);
        }
        if(n) printf("Impossible\n");
        else{
            for(int i=cnt-1;i>=0;i--)printf("%d",repr[i]);
            printf("\n");
        }
    }
    return 0;
}
