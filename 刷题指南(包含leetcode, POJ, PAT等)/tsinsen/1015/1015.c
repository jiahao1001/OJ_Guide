#include <iostream>
using namespace std;

int tri[34][34];
int main(){
    int n;
    cin>>n;

    int i;
    for(i=0;i<n;i++){
        tri[i][0]=tri[i][i]=1;
    }
    for(i=2;i<n;i++){
        for(int j=1;j<i;j++){
            tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
        }
    }
    for(i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<tri[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}