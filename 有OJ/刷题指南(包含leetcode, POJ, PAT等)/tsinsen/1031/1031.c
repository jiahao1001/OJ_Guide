#include <iostream>
using namespace std;

int main(){
    int i,j,n=15;

    for(i=0;i<n;i++){
        for(j=i;j>0;j--)
            cout<<(char)(j+'A');
        cout<<'A';
        for(j=0;j<i;j++)
            cout<<(char)(j+'A'+1);
        cout<<endl;
    }
    return 0;

}