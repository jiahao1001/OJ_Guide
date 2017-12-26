#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include <climits>
#include<vector>
#include<set>
using namespace std;
/*

 _    0
|_| 3 1 4      0   1   2   3   4   5   6     7   8   9
|_| 5 2 6     125  80  55  87  90  79  111   81  127 95
*/
string line[3];
int bt[]={125,80,55,87,90,79,111,81,127,95};
int a[8];
int b[8];
int d(char c){
    return c==' '?0:1;
}
int digit(int p){
    if(p>=12)p++;
    int x = d(line[0][p+1])<<0;
    x+= d(line[1][p+1])<<1;
    x+= d(line[2][p+1])<<2;
    x+=d(line[1][p])<<3;
    x+=d(line[1][p+2])<<4;
    x+=d(line[2][p])<<5;
    x+=d(line[2][p+2])<<6;
    return x;
}
bool check(){
    for(int i=0;i<8;i++)
        if((a[i]|b[i])!=b[i]) return false;
    return true;
}
int main(){
    int t;
    cin>>t;
    getline(cin,line[0]);
    while(t--){
        for(int i=0;i<3;i++)
            getline(cin,line[i]);
        for(int i=0;i<8;i++)
            a[i] = digit(i*3);
        int cnt = 0; //number of possibility
        int x,y,hx,mx,hy,my;
        int ansh,ansm;
        for(x=0;x<1440;x++){
            y = (x-15+1440)%1440;
            hx = x/60,mx = x%60;
            hy = y/60,my = y%60;
            b[0] = bt[hx/10];
            b[1] = bt[hx%10];
            b[2] = bt[mx/10];
            b[3] = bt[mx%10];
            b[4] = bt[hy/10];
            b[5] = bt[hy%10];
            b[6] = bt[my/10];
            b[7] = bt[my%10];
            if(check()) cnt++,ansh = hx, ansm = mx;
        }
        if(cnt>1) cout<<"Not Sure"<<endl;
        else{
            cout<<ansh/10<<ansh%10<<ansm/10<<ansm%10<<endl;
        }
    }
    return 0;
}
