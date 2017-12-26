#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 10;
char pic1[N][N];
int pic2[N][N];
int R,C;
int main()
{
    string cmd;
    while(cin>>cmd,cmd!="ENDOFINPUT"){
        cin>>R>>C;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++) cin>>pic1[i][j], pic1[i][j]-='0';
        cin>>cmd;
        for(int i=0;i<R-1;i++){
            for(int j=0;j<C-1;j++)
                cout<<(pic1[i][j]+pic1[i][j+1]+pic1[i+1][j]+pic1[i+1][j+1])/4;
            cout<<endl;
        }
    }
    return 0;
}
