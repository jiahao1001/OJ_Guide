#include<iostream>
#include<vector>
#include<string.h>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<utility>
#include<float.h>
#include<math.h>
#include<sstream>
#include<stdlib.h>
#include<limits.h>
#include<string>
#include<numeric>
#include<map>
using namespace std;
map<string,int> to;
int main(){
    string words[31]={"zero", "one", "two",
    "three", "four", "five", "six", "seven",
    "eight", "nine", "ten", "eleven", "twelve",
    "thirteen", "fourteen", 
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
    "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
    "eighty", "ninety", "hundred", "thousand", "million"};
    int num[31]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40,50,60,70,80,90,100,1000,1000000};
    for(int i=0;i<31;i++) to[words[i]] = num[i];
    string line;
    string w;
    while(getline(cin,line)){
        if(line.size()==0) break;
        istringstream is(line);
        int n = 0;
        int m=0,t=0;
        int sign = 1;
        while(is>>w){
            if(w=="negative"){
                sign*=-1;
            }else if(w=="thousand"){
                t = n;
                n = 0;
            }else if(w=="million"){
                m = n;
                n = 0;
            }else if(w=="hundred"){
                n*=100;
            }else{
                n+=to[w];
            }
             
            //cout<<n<<endl;
        }
        cout<<sign*(m*1000000+t*1000+n)<<endl;
    }
    return 0;
    
}
