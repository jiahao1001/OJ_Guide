#include <iostream>
using namespace std;

int main(){
    int queue[1000];

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>queue[i];
    }

    int a;
    cin>>a;

    int j=0;
    while(queue[j]!=a&&j<n){
        j++;
    }

    if(j==n)cout<<-1;
    else cout<<j+1;


    return 0;
}