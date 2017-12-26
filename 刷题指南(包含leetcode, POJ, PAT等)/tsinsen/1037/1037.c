#include <iostream>

using namespace std;

int down(int n){
    if(0==n)return 0;
    if(1==n)return 1;
    if(2==n)return 2;
    if(3==n)return 4;

    return down(n-1)+down(n-2)+down(n-3);

}

int main(){

    int n;
    cin>>n;
    if(n<4||n>20)cout<<0;
    else cout<<down(n);


    return 0;
}