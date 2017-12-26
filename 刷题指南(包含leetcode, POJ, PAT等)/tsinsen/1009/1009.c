#include <iostream>

using namespace std;

int main(){
    int n,max,j,min;
    max=-9999; //max
    min=9999;
    int second_max=-9999;
    int second_min=9999;
    long count=0;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>j;
        count+=j*j;
        if(j>max){
            second_max=max;  
            max=j;
        }
        else if(j>second_max)second_max=j;
        if(j<min){
            second_min=min;
            min=j;
        }
        else if(j<second_min)second_min=j;
    }

    cout<<second_max<<endl<<second_min<<endl<<count<<endl;
    return 0;
}