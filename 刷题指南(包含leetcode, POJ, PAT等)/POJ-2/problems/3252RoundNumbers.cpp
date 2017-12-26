#include<iostream>
using namespace std;
static int C[64][64];
int rndnum(int b,int z, unsigned int top){
    int ans = 0;
    if(z>b || top==0) return 0;
    if(top>= (1U<<b)){
        for(int j=max(z,0);j<=b;j++)
            ans += C[b][j];
        return ans;
    }
    ans += rndnum(b-1,z-1,top);
    unsigned int h = 1U<<(b-1);
    if(top>h && b>z) ans += rndnum(b-1,z,top-h);
    return ans;
    
}
int range(int b,int z,int s,int t){
    if(s>=t) return 0;
    return rndnum(b,z,t)-rndnum(b,z,s);
}
int main(){
    for(int i=0;i<64;i++){
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
    }
    unsigned f,l;
    int ans = 0;
    cin>>f>>l;
    for(int i=1;i<=31;i++){
        unsigned int fl = max(f,1U<<(i-1));
        ans += range(i,(i+1)/2,fl,l+1);
    }
    cout<<ans<<endl;
    return 0;
}
