#include <iostream>
#include <math.h>
using namespace std;

int main(){

    

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        double r0,r1;
        double pi=3.1415926;
        r0=r1=0.0;

        double x,y;
        cin>>x>>y;

        double r=sqrt(x*x+y*y);

        int year=0;
        while(r1<=r){
            r1=sqrt(r0*r0+100.0/pi);
            r0=r1;
            year++;
        }

        cout<<year<<endl;

    }



    return 0;
}