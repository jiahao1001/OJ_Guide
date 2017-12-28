#include <iostream>

using namespace std;

int a[10000];
int main(){
    int t,n,m,i,j,x,y;
    cin>>t;

    for(i=0;i<t;i++){
        cin>>n>>m;

        for(j=0;j<n;j++)
            cin>>a[j];

        for(j=0;j<m;j++){
            cin>>x>>y;
            int temp;
            temp=a[x-1];
            a[x-1]=a[y-1];
            a[y-1]=temp;
        }

        for(j=0;j<n;j++)
            cout<<a[j]<<endl;

    }


    return 0;
}