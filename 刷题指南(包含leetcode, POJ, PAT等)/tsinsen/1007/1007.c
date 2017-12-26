#include <iostream>

using namespace std;

int main(){

int n;
    cin>>n;

    int i,j,k,l,p,q;

    for(int c=10000;c<100000;c++){

        int b=c;
        i=c%10;
        j=(c/10)%10;
        k=(c/100)%10;
        l=(c/1000)%10;
        p=c/10000;

        if(i==p&&j==l&&i+j+k+l+p==n)
            cout<<b<<endl;
    }


    for(int c=100000;c<1000000;c++){

        int b=c;
        i=c%10;
        j=(c/10)%10;
        k=(c/100)%10;
        l=(c/1000)%10;
        p=(c/10000)%10;
        q=c/100000;

        if(i==q&&j==p&&k==l&&i+j+k+l+p+q==n)
            cout<<b<<endl;
    }


    return 0;
}