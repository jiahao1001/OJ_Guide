#include <iostream>
#include <math.h>
using namespace std;


bool is_prime(int num){

    //2是特殊的质数
    if (num == 2){
        return true;
    }

    //是否为偶数  
    if (num % 2 == 0){  
        return false;
    }  

    int i, thread=sqrt(num);
    for (i = 3; i <= thread; i += 2) {  
    if (num % i == 0)
        return false;  
    }

    return true;  
}

int main(){
    int a,b;
    bool has=false;
    cin>>a>>b;
    for(;a<=b-2;a++){
        if(a==1)continue;
        if(is_prime(a)&&is_prime(a+2)){
            cout<<a<<" "<<a+2<<endl;
            has=true;
        }
    }
    if(!has)
        cout<<-1<<endl;

    return 0;
}