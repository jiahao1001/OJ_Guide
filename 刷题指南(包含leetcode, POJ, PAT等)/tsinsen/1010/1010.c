#include <iostream>

using namespace std;

// #include<cstdio>
//    int main(void)
//    {
//        long long a;
//        scanf("%d",&a);
//        printf("%X\n",a );
//    }

int main(){

    int n;
    cin>>n;
    switch(n/16)
    {
        case 10:
        cout<<'A';
        break;

        case 11:
        cout<<'B';
        break;

        case 12:
        cout<<'C';
        break;

        case 13:
        cout<<'D';
        break;

        case 14:
        cout<<'E';
        break;

        case 15:
        cout<<'F';
        break;

        default:
        cout<<n/16;
        break;
    }


    switch(n%16)
    {
        case 10:
        cout<<'A'<<endl;
        break;

        case 11:
        cout<<'B'<<endl;
        break;

        case 12:
        cout<<'C'<<endl;
        break;

        case 13:
        cout<<'D'<<endl;
        break;

        case 14:
        cout<<'E'<<endl;
        break;

        case 15:
        cout<<'F'<<endl;
        break;

        default:
        cout<<n%16<<endl;
        break;
    }

    return 0;
}