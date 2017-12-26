#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    int h,m,s;
    s=t%60;
    m=(t/60)%60;
    h=t/3600;

    cout<<h<<':'<<m<<':'<<s<<endl;

    return 0;
}