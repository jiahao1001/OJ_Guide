#include <iostream>

using namespace std;

int main(){

    long n;
    int p;
    cin>>n>>p;

    char bits[100];
    int count=0;

    if(n==0){
        cout<<0;
        return 0;
    }

    while(n!=0){
        if(n%p<10){
            bits[count]=n%p+'0';
        }
        else {
            bits[count]=(n%p-10)+'A';
        }
        n/=p;
        count++;
    }

    for(int i=count;i>=0;i--){
        cout<<bits[i];
    }

    return 0;
}