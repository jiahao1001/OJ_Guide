#include <iostream>

using namespace std;

int main(){

    cin>>n;

    int i,j,k,l;

    for(int c=1000;c<10000;c++){

        int b=c;
        i=c%10;
        j=(c/10)%10;
        k=(c/100)%10;
        l=c/1000;

        if(i==l&&j==k)
            cout<<b<<endl;
    }

    return 0;
}