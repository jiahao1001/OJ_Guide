#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001


int main(){

    int a[MAX]={0};
    int b[MAX]={0};
    int A,B,i,j;
    cin>>A;
    for(i=0;i<A;i++)cin>>a[i];
    cin>>B;
    for(j=0;j<B;j++)cin>>b[j];

    sort(a,a+A);
    sort(b,b+B);

    int andab[2*MAX]={0};
    int orab[MAX]={0};
    int leaveab[MAX]={0};


    i=0;j=0;
    int count_and=0,count_or=0,count_leave=0;

    while(i<A&&j<B){

        bool has=false;

        while(b[j]<a[i]&&j<B){
            andab[count_and]=b[j];
            count_and++;
            j++;
        }
        while(b[j]==a[i]&&j<B){
            orab[count_or]=a[i];
            count_or++;
            j++;
            has=true;
        }

        if(!has){
            leaveab[count_leave]=a[i];
            count_leave++;
        }
        andab[count_and]=a[i];
        count_and++;
        i++;
    }

    if(i==A){
        while(j<B){
            andab[count_and]=b[j];
            count_and++;
            j++;
        }
    }else{
        while(i<A){
            andab[count_and]=a[i];
            count_and++;
            leaveab[count_leave]=a[i];
            count_leave++;
            i++;
        }
    }


    for(i=0;i<count_or;i++)
        cout<<orab[i]<<' ';
    cout<<endl;


    for(i=0;i<count_and;i++)
        cout<<andab[i]<<' ';
    cout<<endl;

    for(i=0;i<count_leave;i++)
        cout<<leaveab[i]<<' ';
    cout<<endl;
    

    return 0;
}