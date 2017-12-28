#include <iostream>

using namespace std;

int main(){
    int n,max,j,min;
    max=-9999; //max
    min=9999;
     count=0;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>j;
        count+=j;
        if(j>max)max=j;
        if(j<min)min=j;
    }

    cout<<max<<endl<<min<<endl<<count<<endl;
    return 0;
}