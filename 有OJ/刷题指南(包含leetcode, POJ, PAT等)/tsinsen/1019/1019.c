#include <iostream>
using namespace std;

int main(){

    int i,j,k,l;

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            for(k=0;k<4;k++)
                for(l=0;l<4;l++)
                        cout<<char(i+'A')<<char(j+'A')<<char(k+'A')<<char(l+'A')<<endl;



    return 0;
}