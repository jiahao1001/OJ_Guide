#include <iostream>

using namespace std;

int get_num(int n);

int main(){

    int n;
    cin>>n;
    cout<<get_num(n)<<endl;

    return 0;
    

}

int get_num(int n){
    if(n==1)
        return 1;
    if(n==2){
        return 2;
    }
    else
        return get_num(n-1)+get_num(n-2);
}