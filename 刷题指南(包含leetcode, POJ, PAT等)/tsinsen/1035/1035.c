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

    int n,i;
    int count;

    cin>>n;
    while(n!=0){
        count=0;
        for(i=2;i<=n;i++)
            if(is_prime(i))
                count+=i;

        cout<<count<<endl;


        cin>>n;
    }





    return 0;
}