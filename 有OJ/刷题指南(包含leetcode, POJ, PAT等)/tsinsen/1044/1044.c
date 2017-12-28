#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n==1||n==2)return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    cin>>n;
    while(n!=0){
        int sum=0;
        for(int i=n;i>0;i--)
            sum+=fibonacci(i);
        cout<<sum<<endl;
        cin>>n;
    }

    return 0;
}