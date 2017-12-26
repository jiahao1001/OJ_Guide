#include <iostream>
#include <string.h>

using namespace std;

int main(){
    int a[30][30], b[30][30],backb[30][30];
    int n,m,i,j,k,l,sum;
    cin>>n>>m;

    memset(b,0,sizeof(b));
    memset(backb,0,sizeof(backb));

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
        b[i][i]=1;
        backb[i][i]=1;
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                sum=0;
                for(l=0;l<n;l++){
                    sum+=a[j][l]*backb[l][k];
                }
                b[j][k]=sum;
            }
        }

        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                backb[j][k]=b[j][k];
            }
        }
    }

    for(j=0;j<n;j++){
        for(k=0;k<n;k++){
            cout<<b[j][k]<<" ";
        }
        cout<<endl;
    }

    return 0;
}