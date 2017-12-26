#include <iostream>

using namespace std;

int main(){

    int n,i,layer=1;
    cin>>n;

    //get layer
    i=1;
    while(n-i>0){
        n=n-i;
        layer++;
        i++;
    }

    if(layer%2==0){
        cout<<n<<'/'<<layer+1-n<<endl;
    }else{
        cout<<layer+1-n<<'/'<<n<<endl;
    }





    return 0;
}