#include <iostream>

using namespace std;

bool is_the_number(int n);

bool is_the_number(int n){
    int bits[3];
    int j=n;

    int i;
    for(i=0;i<3;i++){
        bits[i]=j%10;
        j/=10;
    }

    int count=0;
    for(i=0;i<3;i++){
        count+=bits[i]*bits[i]*bits[i];
    }

    return count==n;

}

int main(){

    int i=100;
    for(;i<1000;i++){
        if(is_the_number(i)){
            cout<<i<<endl;
        }
    }

    return 0;
}



//当然，还可以更短。上面的for循环都是累赘。
//以下为其他同学的解法
// #include<iostream> 
// using namespace std; 
// int main() 
// { 
//     int a,b,c,i; 
//     for(i=100;i<1000;i++){ 
//         a=i%10; 
//         b=i/10%10; 
//         c=i/100; 
//         if(i==a*a*a+b*b*b+c*c*c) 
//         printf("%d/n",i); 
//         } 
// system("pause"); 
// return 0; 
// } 